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
                            <a href="../suite.html">
                                测试套件(
                                <span id="suite-count">0</span>
                                )
                            </a>
                        </li>

                    </ul>
                </header>
                <div id="below-header">
                    <div class="banner" id="headline">
                        <h1>测 试 详 情</h1>
                        <div class="clear"></div>
                    </div>
                    <div id="main">
                        <a class="anchor" id="Tests"></a>
                        <h3>测试样例 Test Cases</h3>
                         <table id="product-info" frame="below">
                            <tr>
                                <th>编号</th>
                                <th>期待值</th>
                                <xsl:for-each select="Data/Case">
                                    <xsl:if test="position() = 1">
                                        <xsl:for-each select="./Param">
                                            <th>
                                                参数
                                                <xsl:value-of select="position()" />
                                            </th>
                                        </xsl:for-each>
                                    </xsl:if>
                                </xsl:for-each>
                            </tr>
                            <xsl:for-each select="Data/Case">
                                <tr>
                                    <td>
                                        <xsl:value-of select="position()" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="./Expected" />
                                    </td>
                                    <xsl:for-each select="./Param">
                                        <td>
                                            <xsl:value-of select="." />
                                        </td>
                                    </xsl:for-each>
                                </tr>
                            </xsl:for-each>
                        </table>
                    </div>
                    <div class="clear"></div>
                    <div id="bottom-banner" class="banner">
                    </div>
                </div>
                <script type="text/javascript" src="/js/common.js" />
                <script type="text/javascript" src="/js/suite_cnt.js" />
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>
