CREATE TABLE NHANVIEN (
	HONV nvarchar(15),
	TENLOT nvarchar(15),
	TENV nvarchar(15),
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
	PRIMARY KEY (MA_NVIEN)
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

DROP TABLE THANNHAN
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

--1.	Tìm các nhân viên làm việc ở phòng số 4
SELECT * FROM NHANVIEN WHERE PHG = 4
--2.	Tìm các nhân viên có mức lương trên 30000
SELECT * FROM NHANVIEN WHERE LUONG > 30000
--3.	Tìm các nhân viên có mức lương trên 25,000 ở phòng 4 hoặc các nhân viên có mức lương trên 30,000 ở phòng 5
SELECT * FROM NHANVIEN WHERE (PHG = 4 AND LUONG > 25000) OR (PHG = 5 AND LUONG > 30000)
--4.	Cho biết họ tên đầy đủ của các nhân viên ở TP HCM
SELECT HONV + ' ' + TENLOT + ' ' + TENV FROM NHANVIEN WHERE DCHI LIKE '%Tp HCM'
--5.	Cho biết họ tên đầy đủ của các nhân viên có họ bắt đầu bằng ký tự 'N'
SELECT HONV + ' ' + TENLOT + ' ' + TENV FROM NHANVIEN WHERE HONV LIKE 'N%'
--6.	Cho biết các nhân viên sinh từ năm 1960 đến 1965
SELECT * FROM NHANVIEN WHERE YEAR(NGSINH) BETWEEN 1960 AND 1965
--7.	Cho biết nhân viên và năm sinh của nhân viên
SELECT HONV, TENLOT, TENV, YEAR(NGSINH) NAMSINH FROM NHANVIEN
--8.	Cho biết nhân viên và tuổi của nhân viên 
SELECT HONV, TENLOT, TENV, DATEDIFF(YYYY, NGSINH, GETDATE()) TUOI FROM NHANVIEN
--9.	Với mỗi phòng ban, cho biết tên phòng ban và địa điểm phòng
SELECT TENPHG, DIADIEM FROM	PHONGBAN PB, DIADIEM_PHG DDP WHERE PB.MAPHG = DDP.MAPHG
--10.	Tìm tên những người trưởng phòng của từng phòng ban
SELECT HONV, TENLOT, TENV FROM NHANVIEN NV, PHONGBAN PB WHERE NV.MANV = PB.TRPHG
--11.	Tìm tên và địa chỉ của tất cả các nhân viên của phòng "Nghiên cứu".
SELECT TENV, DCHI FROM NHANVIEN NV, PHONGBAN PB WHERE NV.PHG = PB.MAPHG AND PB.TENPHG = N'Nghiên cứu'
--12.	Với mỗi đề án ở Hà Nội, cho biết tên đề án, tên phòng ban, họ tên và ngày nhận chức của trưởng phòng của phòng ban chủ trì đề án đó.
SELECT TENDA, TENPHG, TENV, NG_NHANCHUC FROM PHONGBAN PB, NHANVIEN NV, DEAN DA WHERE NV.MANV = PB.TRPHG AND DA.PHONG = PB.MAPHG AND DA.DDIEM_DA LIKE N'%Hà Nội'
--13.	Với mỗi nhân viên, cho biết tên nhân viên và tên người quản lý trực tiếp của nhân viên đó
SELECT A.TENV, B.TENV FROM NHANVIEN A , NHANVIEN B WHERE A.MA_NQL = B.MANV
--14.	Tìm tên những nữ nhân viên và tên người thân của họ
SELECT TENV, TENTN FROM NHANVIEN NV, THANNHAN TN WHERE NV.MANV = TN.MA_NVIEN AND NV.PHAI = N'Nữ'