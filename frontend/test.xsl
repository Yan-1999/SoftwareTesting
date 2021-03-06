<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
            <head>
                <link rel="stylesheet" type="text/css" href="/style.css" />
            </head>
            <body>
                <header>
                    <ul>
                        <li>
                            <a href="/main.xml">
                                <img src="/img/logo.png" class="logo" />
                            </a>
                            <li>
                                <a href="#Summary">
                                    概要
                                </a>
                            </li>
                            <li>
                                <a href="#Failed-Tests">
                                    失败的测试
                                </a>
                            </li>
                            <li>
                                <a href="#Successful-Tests">
                                    成功的测试
                                </a>
                            </li>
                            <li class="right" id="profile">
                                <a href="">测试套件</a>
                            </li>

                        </li>
                    </ul>
                </header>
                <div id="below-header">
                    <div class="banner" id="headline">
                        <h1>测 试 报 告</h1>
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
                                    <th>测试样例数</th>
                                    <td>
                                        <xsl:value-of select="count(TestRun/SuccessfulTests/Test)" />
                                    </td>
                                </tr>
                                <tr>
                                    <th>总失败样例数</th>
                                    <td class="failure">
                                        <xsl:value-of select="count(TestRun/FailedTests/FailedTest)" />
                                    </td>
                                </tr>
                            </table>
                        </div>
                        <div class="card item">
                            <table id="product-info" class="summary" frame="below">
                                <tr>
                                    <th>总测试类数</th>
                                    <td>
                                        <xsl:value-of select="TestRun/Statistics/TestClassNum" />
                                    </td>
                                </tr>
                                <tr>
                                    <th>总测试数</th>
                                    <td>
                                        <xsl:value-of select="TestRun/Statistics/TestSetNum" />
                                    </td>
                                </tr>
                            </table>
                        </div>
                        <div class="clear"></div>
                        <a class="anchor" id="Failed-Tests"></a>
                        <h3>失败的测试 Failed Tests</h3>
                        <table id="product-info" frame="below">
                            <tr>
                                <th>编号</th>
                                <th>名称</th>
                                <th>错误类型</th>
                                <th>文件</th>
                                <th>行号</th>
                                <th>信息</th>
                            </tr>
                            <xsl:for-each select="TestRun/FailedTests/FailedTest">
                                <tr>
                                    <td>
                                        <xsl:value-of select="position()" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="Name" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="FailureType" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="Location/File" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="Location/Line" />
                                    </td>
                                    <td>
                                        <pre>
                                            <xsl:value-of select="Message" />
                                        </pre>
                                    </td>
                                </tr>
                            </xsl:for-each>
                        </table>
                        <a class="anchor" id="Successful-Tests"></a>
                        <h3>成功的测试 Successful Tests</h3>
                        <table id="product-info" frame="below">
                            <tr>
                                <th>编号</th>
                                <th>名称</th>
                            </tr>
                            <xsl:for-each select="TestRun/SuccessfulTests/Test">
                                <tr>
                                    <td>
                                        <xsl:value-of select="@id" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="Name" />
                                    </td>
                                </tr>
                            </xsl:for-each>
                        </table>
                    </div>
                </div>
            </body>
            <script>
                function deleteCookie(name) {
                	document.cookie = name + "=" + "" + ";expires=" +
                		(new Date(1970, 1, 1)).toUTCString() + ";path=/";
                }

                function getCookieAll() {
                	return document.cookie.split(';');
                }
                cs = getCookieAll();
                for(var c of cs)
                    deleteCookie(c.split('=')[0]);
            </script>
        </html>
    </xsl:template>

</xsl:stylesheet>
