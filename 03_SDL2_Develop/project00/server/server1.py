import http.server
import socketserver
import datetime
import logging

PORT = 8000  # 选择一个可用的端口号
DIRECTORY = "./src/"  # 要共享的文件夹的路径

class CustomRequestHandler(http.server.SimpleHTTPRequestHandler):
    def log_message(self, format, *args):
        # 获取当前时间和远程客户端IP地址
        current_time = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        client_ip = self.client_address[0]

        # 获取请求的文件路径
        requested_file = self.path

        # 记录日志
        log_entry = "{} - [{}] - {}\n".format(client_ip, current_time, requested_file)
        logger.info(log_entry)

        # 调用父类的log_message方法，以便继续正常的日志记录
        super().log_message(format, *args)

# 设置日志记录配置
logging.basicConfig(filename='server.log', level=logging.INFO, format='%(asctime)s %(message)s')
logger = logging.getLogger()

Handler = CustomRequestHandler

with socketserver.TCPServer(("", PORT), Handler) as httpd:
    print("文件服务器正在运行，访问地址：http://localhost:{}".format(PORT))
    httpd.serve_forever()