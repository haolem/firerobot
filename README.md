# Robot cứu hỏa v1
![GitHub License](https://img.shields.io/github/license/haolem/firerobot)
![STEM](https://img.shields.io/badge/Cuộc_thi-STEM-blue)

Hướng dẫn thiết lập
===
## TẢI ỨNG DỤNG

1. Truy cập trang dự án [FireRobot](https://github.com/haolem/firerobot).
2. Chọn vào phần Releases -> Assets -> Chọn phiên bản mới nhất.
3. Tải xuống file firerobot-camera-viewer-*.zip

## SỬ DỤNG ỨNG DỤNG

1. Giải nén firerobot-camera-view-*.zip
2. Truy cập thư mục sau giải nén
3. Kết nối với robot qua WIFI
4. Chạy ứng dụng `view.exe`

## CẤU HÌNH KẾT NỐI

1. Mở file `address.cfg` bằng bất kỳ ứng dụng chỉnh sửa văn bản nào.
2. Thay đổi IP bên trong (mặt định là `192.168.4.1`)
3. Lưu file và chạy lại `view.exe`

```js
 .
 |
 + address.cfg
 |
 + landmarks68.dat
 |
 + view.exe
```

## GHI HÌNH

Tính năng ghi hình sẽ được kích hoạt tự động ghi lại toàn bộ thời gian từ lúc chạy ứng dụng `view.exe`. Tính năng hiện tại là **cố định**. Khi ta thoát ứng dụng `view.exe` sẽ có một hộp thoại lưu video hiện ra, ta có thể lựa chọn lưu hoặc không. Chất lượng và độ dài video phụ thuộc vào độ phân giải camera của robot và thời gian sử dụng.
