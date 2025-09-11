from bs4 import BeautifulSoup

html_doc = """
<html>
<head>
    <title>
        Sample
    </title>

</head>
<body>
    <p>
        some text here
    </p>
    <a href = "google.com"> link </a>
    <p>
        second paragraph
    </p>
    <img src="">
    
</body>
</html>
"""
html_doc = html_doc.replace("\n", "")
#prepare soup
soup = BeautifulSoup(html_doc, "html.parser")

#gives a list of attributes for a tag as dict
#print(tag.attrs)

#name attribute=> gives the name of the tag
#tag = soup.head
#print(tag.name)
#tag=soup.a

#contents=>list of all child tags
#tag=soup.html
#print(tag.contents)

#children =>a list iterator of all child tags
#for i in tag.children:
 #   print(i)
 
#parent => name of the parent tag
#parents => list iterator of all parent tags

#string => text within a tag.


#tag=soup.html.head.title

#tag = soup.html.body.p.string
#print(tag)

#to search for a tag
#we can use find or find_all

#tag = soup.find_all('p')
#print(tag)

#for i in tag:
 #   print(i.string)