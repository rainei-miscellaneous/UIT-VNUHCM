Use QLGV

--1. In ra danh sách (mã học viên, họ tên, ngày sinh, mã lớp) lớp trưởng của các lớp.
SELECT MAHV, HO + ' ' + TEN AS HoTen, NGSINH, HOCVIEN.MALOP
FROM HOCVIEN, LOP
WHERE MAHV = TRGLOP

--2. In ra bảng điểm khi thi (mã học viên, họ tên , lần thi, điểm số) môn CTRR của lớp “K12”, 
--sắp xếp theo tên, họ học viên.
SELECT HOCVIEN.MAHV, HO + ' ' + TEN AS HoTen, LANTHI, DIEM
FROM HOCVIEN, KETQUATHI
WHERE HOCVIEN.MAHV = KETQUATHI.MAHV AND 
	  HOCVIEN.MALOP = 'K12' AND 
	  KETQUATHI.MAMH = 'CTRR'
ORDER BY HoTen

--3. In ra danh sách những học viên (mã học viên, họ tên) 
--và những môn học mà học viên đó thi lần thứ nhất đã đạt.
SELECT HOCVIEN.MAHV, HO + ' ' + TEN AS HOTEN, TENMH
FROM HOCVIEN, KETQUATHI, MONHOC
WHERE HOCVIEN.MAHV = KETQUATHI.MAHV AND 
	  MONHOC.MAMH = KETQUATHI.MAMH AND 
	  LANTHI = 1 AND 
	  KQUA = 'Dat'

--4. In ra danh sách học viên (mã học viên, họ tên) 
--của lớp “K11” thi môn CTRR không đạt (ở lần thi 1).
SELECT HOCVIEN.MAHV, HO + ' ' + TEN AS HoTen
FROM HOCVIEN, KETQUATHI
WHERE HOCVIEN.MAHV = KETQUATHI.MAHV AND
	  HOCVIEN.MALOP = 'K11' AND
	  KETQUATHI.MAMH = 'CTRR' AND
	  LANTHI = 1 AND 
	  KQUA = 'Khong Dat'

--6. Tìm tên những môn học mà giáo viên có tên “Tran Tam Thanh” dạy trong học kỳ 1 năm 2006.
SELECT DISTINCT TENMH
FROM MONHOC, GIAOVIEN, GIANGDAY
WHERE MONHOC.MAMH = GIANGDAY.MAMH AND
	  GIAOVIEN.MAGV = GIANGDAY.MAGV AND
	  HOTEN = 'Tran Tam Thanh' AND 
	  HOCKY = 1 AND 
	  NAM = 2006

--7. Tìm những môn học (mã môn học, tên môn học) mà 
--giáo viên chủ nhiệm lớp “K11” dạy trong học kỳ 1 năm 2006.
SELECT MONHOC.MAMH, TENMH
FROM MONHOC, LOP, GIANGDAY
WHERE MONHOC.MAMH = GIANGDAY.MAMH AND
	  GIANGDAY.MAGV = LOP.MAGVCN AND
	  LOP.MALOP = 'K11' AND
	  HOCKY = 1 AND NAM = 2006

--8. Tìm họ tên lớp trưởng của các lớp mà giáo viên có tên “Nguyen To Lan” dạy môn “Co So Du Lieu”.
SELECT HO + ' ' + TEN AS HoTen
FROM HOCVIEN, LOP, GIAOVIEN, GIANGDAY, MONHOC
WHERE HOCVIEN.MAHV = LOP.TRGLOP AND
	  GIANGDAY.MAMH = MONHOC.MAMH AND
	  TENMH = 'Co so du lieu' AND
	  GIANGDAY.MAGV = GIAOVIEN.MAGV AND
	  HOTEN = 'Nguyen To Lan' AND 
	  GIANGDAY.MALOP = LOP.MALOP

--9. In ra danh sách những môn học (mã môn học, tên môn học) phải học liền trước môn “Co So Du Lieu”.
SELECT MHTRUOC.MAMH, MHTRUOC.TENMH
FROM MONHOC MH, MONHOC AS MHTRUOC, DIEUKIEN
WHERE MH.MAMH = DIEUKIEN.MAMH AND
	  MHTRUOC.MAMH = DIEUKIEN.MAMH_TRUOC AND
	  MH.TENMH = 'Co so du lieu'

--10. Môn “Cau Truc Roi Rac” là môn bắt buộc phải học liền trước những môn học (mã môn học, tên môn học) nào.
SELECT MH.MAMH, MH.TENMH
FROM (DIEUKIEN DK INNER JOIN MONHOC MHTRC ON DK.MAMH_TRUOC = MHTRC.MAMH)
	INNER JOIN MONHOC MH ON DK.MAMH = MH.MAMH
WHERE MHTRC.TENMH = 'Cau truc roi rac'

--11. Tìm họ tên giáo viên dạy môn CTRR cho cả hai lớp “K11” và “K12” trong cùng học kỳ 1 năm 2006.
SELECT DISTINCT HOTEN
FROM GIAOVIEN GV INNER JOIN GIANGDAY GD ON GV.MAGV = GD.MAGV
WHERE GD.MAMH = 'CTRR' AND (MALOP = 'K11' OR MALOP = 'K12')
	AND HOCKY = 1 AND NAM = '2006'

--12. Tìm những học viên (mã học viên, họ tên) thi không đạt môn CSDL ở lần thi thứ 1 
--nhưng chưa thi lại môn này.
SELECT HV.MAHV, HO + ' ' + TEN AS HOTEN
FROM HOCVIEN HV INNER JOIN KETQUATHI KQT ON HV.MAHV = KQT.MAHV
WHERE MAMH = 'CSDL' AND KQUA = 'Khong dat'
EXCEPT
SELECT HV.MAHV, HO + ' ' + TEN AS HOTEN
FROM HOCVIEN HV INNER JOIN KETQUATHI KQT ON HV.MAHV = KQT.MAHV
WHERE MAMH = 'CSDL' AND KQUA = 'Khong dat' AND LANTHI > '1'

--13. Tìm giáo viên (mã giáo viên, họ tên) không được phân công giảng dạy bất kỳ môn học nào.
SELECT GV.MAGV, HOTEN
FROM GIAOVIEN GV LEFT JOIN GIANGDAY GD ON GV.MAGV = GD.MAGV
WHERE GD.MALOP IS NULL

--14. Tìm giáo viên (mã giáo viên, họ tên) 
--không được phân công giảng dạy bất kỳ môn học nào thuộc khoa giáo viên đó phụ trách.
SELECT DISTINCT GV.MAGV, HOTEN
FROM (GIAOVIEN GV LEFT JOIN GIANGDAY GD ON GV.MAGV = GD.MAGV)
	LEFT JOIN MONHOC MH ON GD.MAMH = MH.MAMH
EXCEPT
SELECT DISTINCT GV.MAGV, HOTEN
FROM (GIAOVIEN GV LEFT JOIN GIANGDAY GD ON GV.MAGV = GD.MAGV)
	LEFT JOIN MONHOC MH ON GD.MAMH = MH.MAMH
WHERE GV.MAKHOA = MH.MAKHOA

--15. Tìm họ tên các học viên thuộc lớp “K11” thi một môn bất kỳ quá 3 lần 
--vẫn “Khong dat” hoặc thi lần thứ 2 môn CTRR được 5 điểm.
SELECT *
FROM HOCVIEN HV INNER JOIN KETQUATHI KQT ON HV.MAHV = KQT.MAHV
WHERE MALOP = 'K11' AND LANTHI > 3 AND KQUA = 'Khong dat'
UNION
SELECT *
FROM HOCVIEN HV INNER JOIN KETQUATHI KQT ON HV.MAHV = KQT.MAHV
WHERE MALOP = 'K11' AND LANTHI = 2 AND MAMH = 'CTRR' AND DIEM = 5

--16. Tìm họ tên giáo viên dạy môn CTRR cho ít nhất hai lớp trong cùng một học kỳ của một năm học.
SELECT HOTEN
FROM (GIAOVIEN GV LEFT JOIN GIANGDAY GD ON GV.MAGV = GD.MAGV)
WHERE GD.MAMH = 'CTRR'
GROUP BY HOTEN
HAVING COUNT(MALOP) >= 2 
	AND COUNT(DISTINCT HOCKY) < COUNT(HOCKY) 
	AND COUNT(DISTINCT NAM) < COUNT(NAM)

--17. Danh sách học viên và điểm thi môn CSDL (chỉ lấy điểm của lần thi sau cùng).
SELECT HV.MAHV, HO, TEN, NGSINH, GIOITINH, NOISINH, MALOP, DIEM
FROM HOCVIEN HV INNER JOIN KETQUATHI KQT1 ON HV.MAHV = KQT1.MAHV
WHERE MAMH = 'CSDL'
	AND LANTHI >= ALL(SELECT LANTHI
						FROM KETQUATHI KQT2
						WHERE KQT1.MAHV = KQT2.MAHV
						AND KQT1.MAMH = KQT2.MAMH)

--18. Danh sách học viên và điểm thi môn “Co So Du Lieu” (chỉ lấy điểm cao nhất của các lần thi).
SELECT HV.MAHV, HO, TEN, NGSINH, GIOITINH, NOISINH, MALOP, DIEM, LANTHI
FROM (HOCVIEN HV INNER JOIN KETQUATHI KQT1 ON HV.MAHV = KQT1.MAHV)
	INNER JOIN MONHOC MH ON KQT1.MAMH = MH.MAMH
WHERE TENMH = 'Co so du lieu'
	AND DIEM >= ALL(SELECT DIEM
						FROM KETQUATHI KQT2
						WHERE KQT1.MAHV = KQT2.MAHV
						AND KQT1.MAMH = KQT2.MAMH)

--19. Khoa nào (mã khoa, tên khoa) được thành lập sớm nhất.
SELECT MAKHOA, TENKHOA
FROM KHOA
WHERE NGTLAP <= ALL(SELECT NGTLAP
					FROM KHOA)