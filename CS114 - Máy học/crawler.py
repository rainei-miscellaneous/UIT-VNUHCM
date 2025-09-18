import requests
import os
import shutil  # For folder removal
from selenium import webdriver
from selenium.webdriver.common.by import By
import time
from web import car_websites

# Header giả lập trình duyệt
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.81 Safari/537.36"
}

# Ngưỡng kích thước tối thiểu của ảnh (bỏ qua ảnh nhỏ hơn kích thước này)
MIN_WIDTH = 500
MIN_HEIGHT = 300

# Các từ khóa loại trừ không cần tải
EXCLUDED_KEYWORDS = ["icon", "placeholder", "true", "logo", "mahindra-xev-9e", "mahindra-be-6e", "honda-qc1", "honda-activa-e", "royal-enfield-goan-classic-350-review", "royal-enfield-scram-440", "hyundai-ioniq-9", "royal-enfield-goan-classic-350", "interior", "others"]

# Biến toàn cục theo dõi chỉ số ảnh
global_img_idx = 1  # Khởi tạo chỉ số toàn cục

# Hàm tải ảnh
def create_folder_with_prefix(base_path, car_brand):
    start = 0  # Bắt đầu từ 0000
    increment = 1000  # Mỗi lần tăng chỉ số lên 1000
    
    # Lặp để kiểm tra xem thư mục đã tồn tại hay chưa
    while True:
        folder_name = f"{car_brand}-{start:04}-{start + increment:04}"
        folder_path = os.path.join(base_path, folder_name)
        if not os.path.exists(folder_path):
            os.makedirs(folder_path)
            print(f"Tạo thư mục: {folder_path}")
            return folder_path  # Trả về đường dẫn của thư mục mới tạo
        start += increment  # Tăng chỉ số lên 1000 nếu thư mục đã tồn tại

# Hàm tải ảnh
def download_image(img_url, folder="", car="", img_idx=1):
    try:
        # Tên file theo định dạng yêu cầu
        img_name = f"22521027-22520195-22521060.{car}.{img_idx}.jpg"
        # Tải ảnh
        img_data = requests.get(img_url, headers=headers, timeout=10).content
        # Lưu ảnh
        file_path = os.path.join(folder, img_name)
        with open(file_path, "wb") as f:
            f.write(img_data)
        print(f"[+] Lưu thành công: {file_path}")
    except Exception as e:
        print(f"[-] Lỗi khi tải {img_url}: {e}")

# Hàm kiểm tra kích thước ảnh
def is_valid_image(img):
    try:
        width = int(img.get_attribute("naturalWidth"))
        height = int(img.get_attribute("naturalHeight"))
        if width >= MIN_WIDTH and height >= MIN_HEIGHT:
            return True
        else:
            print(f"[-] Bỏ qua ảnh kích thước nhỏ: {width}x{height}")
            return False
    except:
        return False

# Hàm kiểm tra từ khóa loại trừ
def contains_excluded_keywords(img_url):
    for keyword in EXCLUDED_KEYWORDS:
        if keyword in img_url:
            print(f"[-] Bỏ qua ảnh không cần thiết: {img_url}")
            return True
    return False

# Hàm crawl sử dụng Selenium
def crawl_with_selenium(url, car="", img_idx=1, folder_path=""):
    global global_img_idx  # Khai báo biến toàn cục
    print(f"Đang crawl trang với Selenium: {url}")
    try:
        driver = webdriver.Chrome()
        driver.get(url)
        time.sleep(5)  # Đợi trang tải hoàn toàn

        # Lấy tất cả thẻ ảnh
        images = driver.find_elements(By.TAG_NAME, "img")
        print(f"Đã tìm thấy {len(images)} ảnh trong trang.")

        # Tải và lưu từng ảnh
        for img in images:
            img_url = img.get_attribute("src")
            if img_url and img_url.startswith("http"):
                if not contains_excluded_keywords(img_url) and is_valid_image(img):
                    download_image(img_url, folder=folder_path, car=car, img_idx=global_img_idx)
                    global_img_idx += 1  # Tăng chỉ số toàn cục sau mỗi ảnh
                else:
                    print(f"[-] Ảnh bị loại bỏ: {img_url}")

    except Exception as e:
        print(f"[-] Lỗi khi crawl với Selenium: {e}")
    finally:
        driver.quit()

start = time.time()
base_path = "D:\\SEMESTER 5\\CS114_Machine_Learning\\Project"

# Kiểm tra và crawl từng trang
for brand, websites in car_websites.items():
    global_img_idx = 1
    
    # Tạo thư mục cho mỗi hãng xe với tiền tố tự động
    folder_path = create_folder_with_prefix(base_path, brand)
    
    # Crawl tất cả các trang web cho hãng xe hiện tại
    for website in websites:
        try:
            print(f"Đang kiểm tra trang: {website}")
            crawl_with_selenium(website, car=brand, folder_path=folder_path)
        except Exception as e:
            print(f"[-] Lỗi không xác định: {e}")

end = time.time()
print(f"total_time = {end-start}")