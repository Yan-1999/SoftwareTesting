<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <link rel="stylesheet" type="text/css" href="/style.css" />
                <title></title>
            </head>
            <body>
                <header>
                    <ul>
                        <li>
                            <a href="/main.xml">
                                <img src="/img/logo.png" class="logo" />
                            </a>
                        </li>
                        <li>
                            <a href="#Summary">
                                概要
                            </a>
                        </li>
                        <li>
                            <a href="#Tests">
                                测试列表
                            </a>
                        </li>
                        <li class="right" id="profile">
                            <a href="/suite.html">
                                测试套件(
                                <span id="suite-count">0</span>
                                )
                            </a>
                        </li>

                    </ul>
                </header>
                <div id="below-header">
                    <div class="banner" id="headline">
                        <h1>测 试 主 页</h1>
                        <div class="clear"></div>
                    </div>
                    <div id="main">
                        <a class="anchor" id="Summary"></a>
                        <h3>
                            概要 Summary
                        </h3>
                        <div class="card item">
                            <table id="product-info" class="summary" frame="below">
                                <tr>
                                    <th>总组数</th>
                                    <td>
                                        <xsl:value-of select="count(//method)" />
                                    </td>
                                </tr>
                                <tr>
                                    <th>总类数</th>
                                    <td>
                                        <xsl:value-of select="count(TestInfo/Test)" />
                                    </td>
                                </tr>
                                <tr>
                                    <th>语言</th>
                                    <td>
                                        C++
                                        <br />
                                        Python
                                    </td>
                                </tr>
                            </table>
                        </div>
                        <div class="clear"></div>
                        <a class="anchor" id="Tests"></a>
                        <h3>测试集列表 Test Sets</h3>
                        <xsl:for-each select="TestInfo/Test">
                            <a href="/cgi-bin/SoftwareTesting.py?description={@id}">
                                <div class="card item">
                                    <img src="{img}" alt="" />
                                    <span class="item-name">
                                        <xsl:value-of select="name" />
                                    </span>
                                    <span class="producer">
                                        <xsl:for-each select=".//method">
                                            <xsl:value-of select="." />
                                            <xsl:if test="position() &lt; last()">
                                                <xsl:text>, </xsl:text>
                                            </xsl:if>
                                        </xsl:for-each>
                                    </span>
                                    <span class="specification">
                                        <xsl:value-of select="lang" />
                                    </span>
                                </div>
                            </a>
                        </xsl:for-each>
                    </div>
                    <div class="clear"></div>
                    <div id="bottom-banner" class="banner"></div>
                </div>
                <script type="text/javascript" src="/js/common.js" />
                <script type="text/javascript" src="/js/suite_cnt.js" />
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>
