# 导入base64模块和os模块
import base64
import os

# 定义一个函数，接受图片文件名作为参数，返回base64字符串
def image_to_base64(image_file):
    # 以二进制模式打开图片文件
    with open(image_file, "rb") as f:
        # 读取图片数据
        image_data = f.read()
        # 对图片数据进行base64编码，得到一个字节对象
        b64_data = base64.b64encode(image_data)
        # 将字节对象转换为字符串，去掉换行符
        b64_str = b64_data.decode().replace("\n", "")
        # 返回base64字符串
        return b64_str

# 定义一个空列表，用于存储所有图片的base64字符串
b64_list = []

# 使用os模块的listdir函数，获取目录下的所有文件名
file_list = os.listdir("E:\OneDrive - MSFT\学校生活\海大\计算机类\计算机科学与技术导论\IntroCSLib\K6\K6Pics")

# 遍历所有文件名，判断是否以.jpg或.png结尾，如果是，就调用上面定义的函数，将图片转换为base64字符串，并添加到列表中
for file in file_list:
    if file.endswith(".jpg") or file.endswith(".png"):
        b64_str = image_to_base64(os.path.join("E:\OneDrive - MSFT\学校生活\海大\计算机类\计算机科学与技术导论\IntroCSLib\K6\K6Pics", file))
        b64_list.append(b64_str)

# 遍历列表中的每个base64字符串，使用os模块的path.join函数，拼接出outputBase64-照片名.txt文件的完整路径
for i in range(len(b64_list)):
    output_file = os.path.join("E:\OneDrive - MSFT\学校生活\海大\计算机类\计算机科学与技术导论\IntroCSLib\K6\K6Pics\Output", "outputBase64-" + file_list[i] + ".txt")
    # 以写入模式打开outputBase64-照片名.txt文件，写入base64字符串
    with open(output_file, "w") as f:
        f.write(b64_list[i])
    # 关闭文件
    f.close()
