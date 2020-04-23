import requests
import hashlib

URL = "http://docker.hackthebox.eu:35051/"

def find_the_hash(data):
    begin = data.find("<h3 align='center'>")+19
    end = data.find("</h3>")
    md5_str = data[begin:end].encode('utf-8')
    return hashlib.md5(md5_str).hexdigest()


r = requests.Session()
txt = r.get(url=URL)
string = find_the_hash(txt.text)
printed = r.post(url=URL,data={"hash":string})
print(printed.text)