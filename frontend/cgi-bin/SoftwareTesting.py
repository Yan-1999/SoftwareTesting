#!F:\Python39\python.exe
# -*- coding: UTF-8 -*-

import os
import cgi
from sys import stdout
import codecs
from lxml import etree

STYLE_BASE = "../htdocs/"

try:
    form = cgi.FieldStorage()
    description_id = form.getvalue('description')
    stdout = codecs.getwriter("utf-8")(stdout)

    if description_id:
        print("Content-type:text/html;charset=\"utf-8\"\n")
        with open(os.path.join(STYLE_BASE, "main.xml"),
                  encoding="utf-8") as xml_file:
            xml = etree.parse(xml_file)
        test = etree.XPath("/TestInfo/Test[@id=\""
                           + str(description_id) + "\"]")(xml)[0]
        with open(os.path.join(STYLE_BASE, "description.xsl"),
                  encoding="utf-8") as xsl_file:
            transform = etree.XSLT(etree.parse(xsl_file))
        html_s = transform.apply(test)
        print(str(html_s))
    else:
        res = os.popen("SoftwareTesting.exe")
        print(res.read())
except Exception as e:
    print("Content-type:text/plain\n")
    print(e)
