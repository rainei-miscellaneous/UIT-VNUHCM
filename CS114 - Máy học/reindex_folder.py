import os
import shutil

def reindex_images_in_specific_folders(parent_directory, id1, id2, id3, folder_names):
    # Tạo thư mục chung để lưu trữ các ảnh đã được đổi tên
    for folder_name in folder_names:
        new_folder_path = os.path.join(parent_directory, f"[rainei] {folder_name.split('-')[0]}")
        os.makedirs(new_folder_path, exist_ok=True)
        
        # Lấy số đầu tiên từ tên thư mục làm chỉ số bắt đầu
        first_number = int(folder_name.split('-')[1])
        
        folder_path = os.path.join(parent_directory, folder_name)
        
        # Check if the folder exists
        if os.path.isdir(folder_path):
            # List all image files in the folder (assuming jpg, jpeg, png extensions)
            files = sorted([f for f in os.listdir(folder_path) if f.endswith(('jpg', 'jpeg', 'png'))])
            
            # Initialize image index counter starting from the first_number
            counter = first_number
            
            # Loop through and rename each image file
            for file in files:
                old_path = os.path.join(folder_path, file)
                new_filename = f"{id1}-{id2}-{id3}.{folder_name.split('-')[-1]}.{counter}{os.path.splitext(file)[1]}"
                new_path = os.path.join(new_folder_path, new_filename)
                
                # Rename the file by copying it to the new folder
                shutil.copy(old_path, new_path)
                
                # Increment the counter
                counter += 1
            
            print(f"Reindexed images and moved to: {new_folder_path}")
        else:
            print(f"Folder {folder_name} does not exist in {parent_directory}")

if __name__ == "__main__":
    # Set the parent directory (X) and IDs
    parent_directory = "D:\\SEMESTER 5\\CS114_Machine_Learning\\Project"  # Adjust this path as needed
    id1 = "22521027"
    id2 = "22520195"
    id3 = "22521060"
    
    # Specify the folders to process
    folder_names = [
        "Honda-0000-1000", "Honda-1000-2000", "Honda-2000-3000", "Honda-3000-4000", "Honda-4000-5000",
        "Hyundai-0000-1000", "Hyundai-1000-2000", "Hyundai-2000-3000", "Hyundai-3000-4000", "Hyundai-4000-5000",
        "KIA-0000-1000", "KIA-1000-2000", "KIA-2000-3000", "KIA-3000-4000", "KIA-4000-5000"
    ]
    
    # Call the function to reindex images in the specified folders
    reindex_images_in_specific_folders(parent_directory, id1, id2, id3, folder_names)