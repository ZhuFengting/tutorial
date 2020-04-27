from bs4 import BeautifulSoup
import requests

#BeautifulSoup
#解析库soup.p soup.title soup.head
#soup.title.name 获取标签属性
#soup.p.children获得的是迭代器 获取的是子节点
#soup.contains
#soup.descendents 获取的子孙节点
#soup.p.parent  获取父节点
#soup.p.parents 获取祖先节点
#soup.p.friend  获取兄弟节点
 
headers = {
    "User-Agent":"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36"
}
html = requests.get("https://book.douban.com",headers=headers).text
soup = BeautifulSoup(html,"lxml")
print(soup.title)


