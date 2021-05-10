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
              <a href="./index.html">
                测试主页
              </a>
            </li>
          </ul>
        </header>
        <div id="below-header">
          <div class="banner" id="headline">
            <h1>测 试 报 告</h1>
            <div class="clear"></div>
          </div>
          <div id="main">
            <h3>
            概要 Summary
          </h3>
            <div class="card item">
              <table id="product-info" class="summary" frame="below">
                <tr>
                  <th>测试样例数</th>
                  <td>
                    <xsl:value-of select="TestRun/Statistics/Tests" />
                  </td>
                </tr>
                <tr>
                  <th>总失败样例数</th>
                  <td class="failure">
                    <xsl:value-of select="TestRun/Statistics/FailuresTotal" />
                  </td>
                </tr>
                <tr>
                  <th>错误数</th>
                  <td class="failure">
                    <xsl:value-of select="TestRun/Statistics/Errors" />
                  </td>
                </tr>
              </table>
            </div>
            <div class="clear"></div>
            <h3>失败的测试 Failed Tests</h3>
            <table id="product-info" frame= "below">
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
                  <xsl:value-of select="@id" />
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
            <h3>成功的测试 Successful Tests</h3>
            <table id="product-info" frame= "below">
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
    </html>
  </xsl:template>

</xsl:stylesheet>
