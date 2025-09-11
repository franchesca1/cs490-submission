import requests
from bs4 import BeautifulSoup
from pymongo import MongoClient

#establish connection to database server
client = MongoClient()

#select database
db = client['employee']

#select collection/table
collection = db['person']

document = {"job":"developer"}
collection.insert_one(document)

#url = "https://quotes.toscrape.com/"

#response = requests.get(url)

#soup = BeautifulSoup(response.content, "html.parser")

quotes = soup.find_all("div", {"class": "quote"})

doc=[]
for i in quotes:
   quote = i.find('span', {"class": "text"}).string
   author = i.find('small', {"class": "author"}).string
   doc.append({"quote":quote, "author":author})
   
client = MongoClient()

db = client["new_quotes"]

collection = db["data"]

collection.insert_many(doc)

all_dbs = client.list_database_names()
print(all_dbs)
