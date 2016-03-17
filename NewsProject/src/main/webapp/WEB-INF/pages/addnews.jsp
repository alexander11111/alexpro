<%@page contentType="text/html;charset=UTF-8" language="java"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@taglib prefix="spring" uri="http://www.springframework.org/tags"%>
<%@taglib prefix="form" uri="http://www.springframework.org/tags/form"%>
<html>
<head>
<title>Home Page</title>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
</head>
<script type="text/javascript" src="<c:url value="/resources/js/jquery-1.10.2.min.js"/>"></script>
<script type="text/javascript" src="<c:url value="/resources/js/script.js"/>"></script>
<spring:url value="/resources/css/mm_health_photo.jpg" var="urlPic" />
<spring:url value="/resources/css/mm_health_nutr.css" var="urlCss" />
<spring:url value="/resources/css/mm_product_lg.gif" var="urlUser" />
<link rel="stylesheet" href="${urlCss}" type="text/css" />
<script language="javascript">
var d=new Date();
var monthname=new Array("January","February","March","April","May","June","July","August","September","October","November","December");
var TODAY = monthname[d.getMonth()] + " " + d.getDate() + ", " + d.getFullYear();
</script>
</head>
<body bgcolor="#F4FFE4">
<spring:url value="/allNews" var="urlNews" />
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr bgcolor="#D5EDB3">
    <td colspan="2" rowspan="2"><img src="${urlPic}" alt="Header image" width="382" height="101" border="0" /></td>
    <td width="443" height="50" id="logo" valign="bottom" align="center" nowrap="nowrap">ALEXSoft Company</td>
    <td width="290">&nbsp;</td>
  </tr>

  <tr bgcolor="#D5EDB3">
    <td height="51" id="tagline" valign="top" align="center"><spring:message code="news.add.NewsRegistration"/></td>
	<td width="290">&nbsp;</td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#5C743D"><img src="css/mm_spacer.gif" alt="" width="1" height="2" border="0" /></td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#99CC66" background="css/mm_dashed_line.gif"><img src="css/mm_dashed_line.gif" alt="line decor" width="4" height="3" border="0" /></td>
  </tr>

  <tr bgcolor="#99CC66">
  <td>&nbsp;</td>
  	<td colspan="3" id="dateformat" height="20"><a href=${urlNews}><spring:message code="news.add.home"/></a>&nbsp;&nbsp;::&nbsp;&nbsp;<script language="JavaScript" type="text/javascript">
      document.write(TODAY);	</script>	</td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#99CC66" background="css/mm_dashed_line.gif"><img src="css/mm_dashed_line.gif" alt="line decor" width="4" height="3" border="0" /></td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#5C743D"><img src="css/mm_spacer.gif" alt="" width="1" height="2" border="0" /></td>
  </tr>
 <tr>
    <td width="40">&nbsp;</td>
    <td colspan="2" valign="top">&nbsp;<br />
    &nbsp;<br />
	<form:form action="" method="post" commandName="UserModel">
    <table border="0" cellspacing="0" cellpadding="2" width="770">
        <tr>
          <td class="pageName" colspan="4"><spring:message code="news.add.NewsRegistration"/><br />
		  &nbsp;<br />		  </td>
        </tr>
        <tr>
          <td width="262" height="225" rowspan="4" align="center" class="subHeader"><img src="${urlUser}" alt="large product photo" border="0" /></td>
          <td width="29" rowspan="5">&nbsp;</td>
          <td width="140" class="subHeader"><div align="left" class="bodyText"><strong><spring:message code="news.add.Title"/></strong><br />
            </div></td>
          <td width="304" class="subHeader">
            <label for="Title"></label>
              <label for="Title2"></label>
              <input type="text" name="title" id="title">
              <!--form:input id="title" path="title" /-->
          </tr>
        <tr>
          <td height="120" valign="top" class="bodyText"><strong><spring:message code="news.add.Category"/></strong></td>
          <td height="120" valign="top" class="bodyText">
            <table width="200">
              <tr>
                <td><label>
                  <input type="radio" name="category" value="0" id="Category_0" />
                <spring:message code="news.add.cat.politics"/></label></td>
                </tr>
              <tr>
                <td><label>
                  <input type="radio" name="category" value="1" id="Category_1" />
                <spring:message code="news.add.cat.events"/></label></td>
                </tr>
              <tr>
                <td><label>
                  <input type="radio" name="category" value="2" id="Category_2" />
                <spring:message code="news.add.cat.sport"/></label></td>
                </tr>
              <tr>
                <td><label>
                  <input type="radio" name="category" value="3" id="Category_3" />
                <spring:message code="news.add.cat.auto"/></label></td>
                </tr>
              </table>
            </td>
        </tr>
        <tr>
          <td height="25" valign="top" class="bodyText"><strong><spring:message code="news.add.Brief"/></strong></td>
          <td height="25" valign="top" class="bodyText">
            <label for="brief"></label>
            <textarea name="brief" id="brief" cols="45" rows="5"></textarea>
            </td>
        </tr>
        <tr>
          <td height="90" valign="top" class="bodyText"><strong><spring:message code="news.add.Content"/></strong></td>
          <td height="90" valign="top" class="bodyText">
            <label for="content"></label>
            <textarea name="content" id="content" cols="45" rows="5"></textarea>
            </td>
        </tr>
        <tr>
          <td width="262" height="34" align="center" valign="top" class="subHeader"><span class="quote">
            <input type="button" name="c2" id="c2" value="load"/>
          </span></td>
          <td height="34" valign="top" class="quote">&nbsp;</td>
          <td height="34" valign="top" class="quote"><input type="button" name="c" id="c" value=<spring:message code="news.add.Add"/> onClick="newsAdd();"/></td>
        </tr>
      </table>
      </form:form>
    </td>
    <td width="290">&nbsp;</td>
  </tr>

 <tr>
    <td width="40" height="19">&nbsp;</td>
    <td width="342">&nbsp;</td>
    <td width="443">&nbsp;</td>
	<td width="290">&nbsp;</td>
  </tr>
</table>
<spring:url value="/newsAdd" var="urlAdd" />
<spring:url value="/userRegistrationReflect" var="urlRegsR" />
<script>

function newsAdd()
{
	//alert("Hello Add news!");
    $.ajax({
        type: "POST",
        url: "${urlAdd}",
        data: 
        	"&title=" + $('#title').val()+
        	"&brief=" + $('#brief').val()+      	
        	"&content=" + $('#content').val()+
        	"&categoryID=" + $('input:radio[name=category]:checked').val(), 
        success: function(response){
        	if (response=="1") alert("Data added successfully!");else
        	if (response=="0") alert("Error validation!");
        },
        error: function(e){
            alert('Error: ' + e);
        }
    });
}
function GoLink1()
{
	alert("Hello Registration!");
    $.ajax({
        type: "GET",
        url: "${urlRegsR}",
        data: 
        	"login=0",
        success: function(response){
        	alert("Login Ok!");
        },
        error: function(e){
            alert('Error: ' + e);
        }
    });
}
</script>

</body>
</html>
