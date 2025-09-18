DROP TABLE NHANVIEN
CREATE TABLE NHANVIEN (
	HONV nvarchar(15),
	TENLOT nvarchar(15),
	TENNV nvarchar(15),
	MANV nvarchar(9),
	NGSINH date,
	DCHI nvarchar(30),
	PHAI nvarchar(3),
	LUONG float,
	MA_NQL nvarchar(9),
	PHG int
	PRIMARY KEY (MANV)
)

CREATE TABLE PHONGBAN (
	TENPHG nvarchar(15),
	MAPHG int,
	TRPHG nvarchar(9),
	NG_NHANCHUC date
	PRIMARY KEY (MAPHG)
)

CREATE TABLE DIADIEM_PHG (
	MAPHG int,
	DIADIEM	nvarchar(15)
	PRIMARY KEY (MAPHG, DIADIEM)
)

CREATE TABLE DEAN (
	TENDA nvarchar(15),
	MADA int,
	DDIEM_DA nvarchar(15),
	PHONG int
	PRIMARY KEY (MADA)
)

CREATE TABLE CONGVIEC (
	MADA int,
	STT int,
	TEN_CONG_VIEC nvarchar(50)
	PRIMARY KEY (MADA, STT)
)

CREATE TABLE PHANCONG (
	MA_NVIEN nvarchar(9),
	MADA int,
	STT int,
	THOIGIAN float
	PRIMARY KEY (MA_NVIEN, MADA)
)

CREATE TABLE THANNHAN (
	MA_NVIEN nvarchar(9),
	TENTN nvarchar(15),
	PHAI nvarchar(3),
	NGSINH datetime,
	QUANHE nvarchar(15)
	PRIMARY KEY (MA_NVIEN, TENTN)
)

SET DATEFORMAT DMY;

INSERT INTO NHANVIEN VALUES (N'Đinh', N'Bá', N'Tiên', '009', '11/02/1960', N'119 Cống Quỳnh, Tp HCM', 'Nam', 30000, '005', 5)
INSERT INTO NHANVIEN VALUES (N'Nguyễn', N'Thanh', N'Tùng', '005', '20/08/1962', N'222 Nguyễn Văn Cừ, Tp HCM', 'Nam', 40000, '006', 5)
INSERT INTO NHANVIEN VALUES (N'Bùi', N'Ngọc', N'Hằng', '007', '11/3/1954', N'332 Nguyễn Thái Học, Tp HCM', 'Nam', 25000, '001', 4)
INSERT INTO NHANVIEN VALUES (N'Lê', N'Quỳnh', N'Như', '001', '01/02/1967', N'291 Hồ Văn Huê, Tp HCM', N'Nữ', 43000, '006', 4)
INSERT INTO NHANVIEN VALUES (N'Nguyễn', N'Mạnh', N'Hùng', '004', '04/03/1967', N'95 Bà Rịa, Vũng Tàu', 'Nam', 38000, '005', 5)
INSERT INTO NHANVIEN VALUES (N'Trần', N'Thanh', N'Tâm', '003', '04/05/1957', N'34 Mai Thị Lự, Tp HCM', 'Nam', 25000, '005', 5)
INSERT INTO NHANVIEN VALUES (N'Trần', N'Hồng', N'Quang', '008', '01/09/1967', N'80 Lê Hồng Phong, Tp HCM', 'Nam', 25000, '001', 4)
INSERT INTO NHANVIEN VALUES (N'Phạm', N'Văn', N'Vinh', '006', '01/01/1965', N'45 Trưng Vương, Hà Nội', N'Nữ', 55000, NULL, 1)

INSERT INTO PHONGBAN VALUES(N'Nghiên cứu', 5, '005', '22/05/1978')
INSERT INTO PHONGBAN VALUES(N'Điều hành', 4, '008', '01/01/1985')
INSERT INTO PHONGBAN VALUES(N'Quản lý', 1, '006', '19/06/1971')

SET DATEFORMAT DMY
INSERT INTO THANNHAN VALUES('005', N'Trinh', N'Nữ', '05/04/1976', N'Con gái')
INSERT INTO THANNHAN VALUES('005', N'Khang', N'Nam', '25/10/1973', N'Con trai')
INSERT INTO THANNHAN VALUES('005', N'Phương', N'Nữ', '03/05/1948', N'Vợ chồng')
INSERT INTO THANNHAN VALUES('001', N'Minh', N'Nam', '29/02/1932', N'Vợ chồng')
INSERT INTO THANNHAN VALUES('009', N'Tiến', N'Nam', '01/01/1978', N'Con trai')
INSERT INTO THANNHAN VALUES('009', N'Châu', N'Nữ', '30/12/1978', N'Con gái')
INSERT INTO THANNHAN VALUES('009', N'Phương', N'Nữ', '05/05/1957', N'Vợ chồng')

INSERT INTO	DEAN VALUES('San pham X', 1, N'Vũng Tàu', 5)
INSERT INTO	DEAN VALUES('San pham Y', 2, N'Nha Trang', 5)
INSERT INTO	DEAN VALUES('San pham Z', 3, N'TP HCM', 5)
INSERT INTO	DEAN VALUES('Tin hoa hoc', 10, N'Hà Nội', 4)
INSERT INTO	DEAN VALUES('Cap quang', 20, N'TP HCM', 1)
INSERT INTO	DEAN VALUES('Dao tao', 30, N'Hà Nội', 4)

INSERT INTO DIADIEM_PHG VALUES(1, 'TP HCM')
INSERT INTO DIADIEM_PHG VALUES(4, 'Hà Nội')
INSERT INTO DIADIEM_PHG VALUES(5, 'TAU')
INSERT INTO DIADIEM_PHG VALUES(5, 'NHA TRANG')
INSERT INTO DIADIEM_PHG VALUES(5, 'TP HCM')

INSERT INTO PHANCONG VALUES('009', 1, 1, 32)
INSERT INTO PHANCONG VALUES('009', 2, 2, 8)
INSERT INTO PHANCONG VALUES('004', 3, 1, 40)
INSERT INTO PHANCONG VALUES('003', 1, 2, 20.0)
INSERT INTO PHANCONG VALUES('003', 2, 1, 20.0)
INSERT INTO PHANCONG VALUES('008', 10, 1, 35)
INSERT INTO PHANCONG VALUES('008', 30, 2, 5)
INSERT INTO PHANCONG VALUES('001', 30, 1, 20)
INSERT INTO PHANCONG VALUES('001', 20, 1, 15)
INSERT INTO PHANCONG VALUES('006', 20, 1, 30)
INSERT INTO PHANCONG VALUES('005', 3, 1, 10)
INSERT INTO PHANCONG VALUES('005', 10, 2, 10)
INSERT INTO PHANCONG VALUES('005', 20, 1, 10)
INSERT INTO PHANCONG VALUES('007', 30, 2, 30)
INSERT INTO PHANCONG VALUES('007', 10, 2, 10)

INSERT INTO CONGVIEC VALUES(1, 1, 'Thiet ke san pham X')
INSERT INTO CONGVIEC VALUES(1, 2, 'Thu nghiem san pham X')
INSERT INTO CONGVIEC VALUES(2, 1, 'San xuat san pham Y')
INSERT INTO CONGVIEC VALUES(2, 2, 'Quang cao san pham Y')
INSERT INTO CONGVIEC VALUES(3, 1, 'Khuyen mai san pham Z')
INSERT INTO CONGVIEC VALUES(10, 1, 'Tin hoc hoa nhan su tien luong')
INSERT INTO CONGVIEC VALUES(10, 2, 'Tin hoc hoa phong Kinh doanh')
INSERT INTO CONGVIEC VALUES(20, 1, 'Lap dat cap quang')
INSERT INTO CONGVIEC VALUES(30, 1, 'Dao tao nhan vien Marketing')
INSERT INTO CONGVIEC VALUES(30, 2, 'Dao tao chuyen vien vien thiet ke')

SELECT * FROM NHANVIEN

--1.	Cho biết số lượng đề án của công ty
SELECT COUNT(MADA) SLDA FROM DEAN

--2.	Cho biết số lượng đề án do phòng “Nghiên cứu” chủ trì
SELECT COUNT(*) SLDA FROM PHONGBAN PB, DIADIEM_PHG DDP WHERE DDP.MAPHG = PB.MAPHG AND TENPHG = N'Nghiên cứu'

--3.	Cho biết lương trung bình của các nữ nhân viên
SELECT AVG(LUONG) LUONGTB FROM NHANVIEN WHERE PHAI = N'Nữ'

--4.	Cho biết số thân nhân của nhân viên “Đinh Bá Tiến”
SELECT COUNT(MA_NVIEN) SOTN FROM THANNHAN TN, NHANVIEN NV WHERE TN.MA_NVIEN = NV.MANV AND NV.HONV = N'Đinh' AND NV.TENLOT = N'Bá' AND NV.TENNV = N'Tiên'

--5.	Với mỗi đề án, liệt kê tên đề án và tổng số giờ làm việc một tuần của tất cả nhân viên tham gia đề án đó.
SELECT TENDA, SUM(PC.THOIGIAN) TONGTHOIGIAN FROM PHANCONG PC, DEAN DA WHERE DA.MADA = PC.MADA GROUP BY TENDA

--6.	Với mỗi đề án, cho biết tên đề án và số nhân viên tham gia đề án.
SELECT TENDA, COUNT(PC.MA_NVIEN) SOLUONGNVTHAMGIA FROM PHANCONG PC, DEAN DA WHERE DA.MADA = PC.MADA GROUP BY TENDA

--7.	Với mỗi nhân viên có số thân nhân lớn hơn 2, cho biết họ và tên nhân viên và số lượng thân nhân của nhân viên đó.
SELECT HONV, TENNV , COUNT(TENTN) SOTN FROM NHANVIEN NV, THANNHAN TN WHERE TN.MA_NVIEN = NV.MANV GROUP BY HONV, TENNV HAVING COUNT(TENTN) > 2

--8.	Với mỗi nhân viên, cho biết họ tên nhân viên và số lượng đề án mà nhân viên đó tham gia.
SELECT NV.HONV + ' ' + NV.TENLOT + ' ' + NV.TENNV AS HOTEN, COUNT(MA_NVIEN) SLDA FROM NHANVIEN NV, PHANCONG PC WHERE PC.MA_NVIEN = NV.MANV 
GROUP BY NV.HONV, NV.TENLOT, NV.TENNV

--9.	Với mỗi nhân viên, cho biết họ tên và số lượng nhân viên mà nhân viên đó quản lý trực tiếp
SELECT NV.HONV + ' ' + NV.TENLOT + ' ' + NV.TENNV AS HOTEN, COUNT(QL.MA_NQL) SLQL FROM NHANVIEN NV LEFT JOIN NHANVIEN QL
ON NV.MANV = QL.MA_NQL
GROUP BY NV.HONV, NV.TENLOT, NV.TENNV

--10.	Với mỗi phòng ban, liệt kê tên phòng ban và lương trung bình của những nhân viên làm việc cho phòng ban đó.
SELECT TENPHG, AVG(LUONG) LUONGTB FROM PHONGBAN PB, NHANVIEN NV WHERE PB.MAPHG = NV.PHG GROUP BY TENPHG

--11.	Với các phòng ban có mức lương trung bình trên 40,000, liệt kê tên phòng ban và số lượng nhân viên của phòng ban đó.
SELECT TENPHG, COUNT(NV.PHG) SLNV FROM PHONGBAN PB, NHANVIEN NV WHERE PB.MAPHG = NV.PHG GROUP BY TENPHG HAVING AVG(NV.LUONG) > 40000

--12.	Cho biết số đề án diễn ra tại từng địa điểm
SELECT DDIEM_DA, COUNT(MADA) SLDA FROM DEAN GROUP BY DDIEM_DA

--13.	Với mỗi đề án, cho biết tên đề án và số lượng công việc của đề án này.
SELECT TENDA, COUNT(CV.MADA) SLCONGVIEC FROM DEAN DA, CONGVIEC CV WHERE DA.MADA = CV.MADA GROUP BY TENDA

--14.	Với mỗi công việc trong đề án có mã đề án “Dao Tao”, cho biết số lượng nhân viên được phân công
SELECT TEN_CONG_VIEC, COUNT(PC.MA_NVIEN) SLNHANVIEN 
FROM CONGVIEC CV, DEAN DA, PHANCONG PC
WHERE CV.MADA = PC.MADA AND PC.MADA = DA.MADA AND TENDA = 'Dao tao'
GROUP BY TEN_CONG_VIEC

--15.	Với mỗi phòng ban có mức lương trung bình trên 30,000, cho biết tên phòng ban và số lượng đề án mà phòng ban đó chủ trì.
SELECT TENPHG, COUNT(DISTINCT DA.MADA) SLDA FROM NHANVIEN NV, DEAN DA, PHONGBAN PB
WHERE NV.PHG = DA.PHONG AND PB.MAPHG = DA.PHONG 
GROUP BY TENPHG
HAVING AVG(NV.LUONG) > 30000
			
--16.	Với mỗi phòng ban, cho biết tên phòng ban và số lượng đề án mà phòng ban đó chủ trì yêu cầu giảm dần theo số lượng đề án.
SELECT TENPHG, COUNT(DA.MADA) SLDA 
FROM PHONGBAN PB, DEAN DA 
WHERE DA.PHONG = PB.MAPHG 
GROUP BY TENPHG 
ORDER BY COUNT(DA.MADA) DESC