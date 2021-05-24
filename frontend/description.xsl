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
                        <h1>测 试 集 详 情</h1>
                        <div class="clear"></div>
                    </div>
                    <div id="main">
                        <a class="anchor" id="Summary"></a>
                        <h3>概要 Breif</h3>
                        <div id="breif">
                            <div id="item-pic-and-cart">
                                <div id="item-pic" class="card">
                                    <img src="{Test/img}" alt="" />
                                </div>
                            </div>
                            <div class="card card-product-info">
                                <table id="product-info" frame="below" class="summary">
                                    <tr>
                                        <th>名称</th>
                                        <td>
                                            <xsl:value-of select="Test/name" />
                                        </td>
                                    </tr>
                                    <tr>
                                        <th>类名</th>
                                        <td>
                                            <xsl:value-of select="Test/class" />
                                        </td>
                                    </tr>
                                    <tr>
                                        <th>方法数</th>
                                        <td>
                                            <xsl:value-of select="count(Test/func)" />
                                        </td>
                                    </tr>
                                    <tr>
                                        <th>测试组数</th>
                                        <td>
                                            <xsl:value-of select="count(Test//method)" />
                                        </td>
                                    </tr>
                                    <tr>
                                        <th>语言</th>
                                        <td>
                                            <xsl:value-of select="Test/lang" />
                                        </td>
                                    </tr>
                                    <tr>
                                        <th>版本</th>
                                        <td>
                                            <xsl:value-of select="Test/ver" />
                                        </td>
                                    </tr>
                                </table>
                            </div>
                        </div>
                        <div class="clear"></div>
                        <a class="anchor" id="Tests"></a>
                        <h3>测试列表 Tests</h3>
                         <table id="product-info" frame="below">
                            <tr>
                                <th>类名</th>
                                <th>方法名</th>
                                <th>测试方法</th>
                                <th>语言</th>
                                <th>版本</th>
                                <th>
                                    <!-- <input type="button" action="" value="全部加入测试套件" /> -->
                                    加入/移出测试套件
                                </th>
                            </tr>
                            <xsl:for-each select="//method">
                                <tr>
                                    <td>
                                        <xsl:value-of select="../../class" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="../name" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="." />
                                    </td>
                                    <td>
                                        <xsl:value-of select="../../lang" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="../../ver" />
                                    </td>
                                    <td>
                                        <input type="button" value="加入测试套件"
                                        id="{concat(normalize-space(../../class), ':', normalize-space(../name), ':', normalize-space(.))}"
                                        onclick="AddToSuite(this)" />
                                    </td>
                                </tr>
                            </xsl:for-each>
                        </table>
                    </div>
                    <div class="clear"></div>
                    <div id="bottom-banner" class="banner">
                    </div>
                </div>
                <script type="text/javascript" src="/js/common.js" />
                <script type="text/javascript" src="/js/description.js" />
                <script type="text/javascript" src="/js/suite_cnt.js" />
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>
