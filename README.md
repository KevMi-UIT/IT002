### GIẢNG VIÊN

- Thầy Khánh Nguyễn - khanhnd@uit.edu.vn
- Thầy Nguyễn Tấn Toàn - toannt@uit.edu.vn

### ĐỀ THI THỰC HÀNH

#### 1

Xây dựng game xe tăng, biết răng trong một bản đồ của game sẽ có nhiều xe tăng cùng tham chiến và danh sách các loại vật phẩm khác và 1 boss. Mỗi xe tăng sẽ có một số hiệu, tên, lượng sinh mệnh hiện tại của riêng mình (lượng sinh mệnh bắt đầu của mỗi xe tăng là 10). Vật phẩm trong game sẽ có 2 loại: đạn được và sinh mệnh. Một vật phẩm sẽ có mã, tên. Vật phẩm đạn dược sẽ có thêm thông tin số lần sử dụng, lượng sát thương. Hiện tại trò chơi có 2 loại đan dược: đạn đơn và đạn đôi. Mỗi đạn đơn khi thực hiện bắt từ xe tăng sẽ có 1 âm thanh “BUM” tạo ra, đạn đôi có 2 âm thanh “BUM BUM” tạo ra (tương lai sẽ phát triển thêm các loại đạn có cách thức hoạt động khác nhau). Vật phẩm là sinh mệnh sẽ thêm thông tin lượng sinh mệnh xe tăng hồi phục nếu nhặt được. Boss sẽ có tên, sinh mệnh (lượng sinh mệnh bắt đầu là 20) và sát thương mỗi lượng tấn công. Mục tiêu của xe tăng là hạ gục boss. Trên đường đạt mục tiêu các xe tăng sẽ nhặt các vật phẩm sinh mệnh để hồi sinh mệnh, nhặt đạn dược để có vũ khí tấn công đối phương và boss. Áp dụng tư tưởng lập trình hướng đối tượng (bắt buộc sử dụng kế thừa, đa hình) xây dựng chương trình cho game trên và thực hiện các tính năng sau:

- Nhập thông tin của một bản đồ game. Mỗi xe tăng sẽ nhặt ngẫu nhiên 1 trong các vật phẩm vừa nhập ở trên (hàm random: int rand(void)).
- Tìm xe tăng có sức sát thương lớn nhất tại thời điểm hiện tại của trò chơi nếu bắn 1 lượt đạn.
- Tìm xe tăng có tổng sát thương lớn nhất nếu bắt hết đạn ở thời điểm hiện tại, và xuất ra quá trình giả lập trao đổi sát thương của xe tăng đó với boss (2 bên thay phiên bắn nhau) cho đến khi cả 2 cùng hết đạn.

#### 2

Ứng dụng quản trị công việc của tổ chức với nhu cầu như sau:
- Quản trị được danh sách người dùng sử dụng hệ thống. Mỗi user cần mã số, tên, vai trò
- Thông tin công việc với thông tin: id, tiêu đề, mô tả, ngày kết thúc, danh sách các công việc liên quan cần hoàn thành trước đó, trạng thái, người tạo, người thực hiện
- Quản trị danh sách dự án, mỗi dự án sẽ có nhiều công việc cần thực hiện, mã dự án, tên, mô tả, thông tin người quản trị, các tài nguyên tập tin liên quan công việc. Hiện tại, tài nguyên đang được hỗ trợ gồm tập tin txt, tập tin dạng hình ảnh. Mỗi thông tin tài nguyên sẽ đại diện cho một file trên hệ thống máy chủ với đường dẫn URL khác nhau cùng với tiêu đề và mô tả nội dung. Nếu là tập tin hình ảnh thì thêm thông tin kích thước 2 chiều của bức ảnh. Mỗi dạng tài nguyên sẽ có hiển thị khác nhau.
- Ở tính năng lưu, ứng dụng có các bộ Exporter: AExporter và BExporter để hỗ trợ lưu trữ thông tin dự án vào tập tin theo các định dạng tương tự (tương lai sẽ thêm các kiểu Exporter khác). Khi thực hiện thao tác Export (Xuất) thì AExporter sẽ tạo ra file .txt với tên file là mã số của dự án kết hợp với mã của bộ Exporter (dự án mã số DA0001 thì lưu ở tập tin DA0001_A.txt), trong tập tin này sẽ có dòng “A Exporter” ở đầu sau đó là thông tin dự án và danh sách công việc. tượng tự đối với Bexporter nhưng tạo ra file .txt với tên file là mã số của dự án kết hợp với mã của bộ Exporter (dự án mã số DA0001 thì lưu ở tập tin DA0001_B.txt) và dòng bắt đầu của file “B Exporter” ở đầu sau đó là thông tin dự án và danh sách công việc.

Áp dựng tư tưởng lập trình hướng đối tượng (bắt buộc có sử dụng kế thừa, đa hình), hãy thiết kế ứng dụng như trên với một số tính năng sau:
  - Cho phép nhập danh sách thông tin N dự án (mỗi dự án người dùng sẽ chọn 1 bộ Exporter khi tạo dự án)
  - Tìm thông tin các dự án sử dụng nhiều tài nguyên dạng hình ảnh nhất (Để đơn giản hoá, các tài nguyên dạng tập tin txt khi hiển thị, sinh viên chỉ cần ghi dòng File: txt và tiếp đó là thông tin cơ bản của tập tin txt, đối với tập tin hình ảnh thì ghi dòng đầu tiền File:Image và tiếp đó là thông tin của tập tin hình ảnh)
  -Sử dụng bộ Exporter đã chọn cho từng dự án, tiến hành lưu thông tin các dự án ra tập tin bằng bộ Exporter đã chọn khi khởi tạo.

> [!WARNING]
> Đề thầy Toàn cho ba chấm 🌝. Chúc may mắn.
