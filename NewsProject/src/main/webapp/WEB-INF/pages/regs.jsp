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


<body bgcolor="#F4FFE4">
<spring:url value="/allNews" var="urlNews" />
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr bgcolor="#D5EDB3">
    <td colspan="2" rowspan="2"><img src="${urlPic}" alt="Header image" width="382" height="101" border="0" /></td>
    <td width="443" height="50" id="logo" valign="bottom" align="center" nowrap="nowrap">ALEXSoft Company</td>
    <td width="290">&nbsp;</td>
  </tr>

  <tr bgcolor="#D5EDB3">
    <td height="51" id="tagline" valign="top" align="center">REGISTRATION</td>
	<td width="290">&nbsp;</td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#5C743D"><img src="/resources/css/mm_spacer.gif" alt="" width="1" height="2" border="0" /></td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#99CC66" background="/resources/css/mm_dashed_line.gif"><img src="/resources/css/mm_dashed_line.gif" alt="line decor" width="4" height="3" border="0" /></td>
  </tr>

  <tr bgcolor="#99CC66">
  <td>&nbsp;</td>
  	<td colspan="3" id="dateformat" height="20"><a href=${urlNews}>HOME</a>&nbsp;&nbsp;::&nbsp;&nbsp;<script language="JavaScript" type="text/javascript">
      document.write(TODAY);	</script>	</td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#99CC66" background="/resources/css/mm_dashed_line.gif"><img src="/resources/css/mm_dashed_line.gif" alt="line decor" width="4" height="3" border="0" /></td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#5C743D"><img src="/resources/css/mm_spacer.gif" alt="" width="1" height="2" border="0" /></td>
  </tr>
 <tr>
    <td width="40">&nbsp;</td>
    <td colspan="2" valign="top">&nbsp;<br />&nbsp;<br />
    <spring:url value="/userAdd" var="urlRegs" />
	<form:form action="${urlRegs}" method="post" commandName="UserModel">
    <table border="0" cellspacing="0" cellpadding="2" width="751">
        <tr>
          <td class="pageName" colspan="4">PAGE REGISTRATION<br/>&nbsp;<br /></td>
        </tr>
        <tr>
          <td width="262" height="250" rowspan="11" align="center" class="subHeader"><img src="${urlUser}" alt="large product photo" border="0" /></td>
          <td width="29" rowspan="11">&nbsp;</td>
          <td width="140" class="subHeader">
          <div align="left" class="bodyText">
          <strong><spring:message code="user.login" /></strong><br />
          </div></td>
           <td width="304" class="subHeader">
            <form:input type="text" name="login" id="login" path="login"/>
          </td>      
        </tr>
        <tr>
            <td height="25" colspan="2" valign="top" >
            <form:errors path="login" cssStyle="color: red;" />
            </td>
        </tr>
        <tr>
          <td height="25" valign="top" class="bodyText"><strong>Password*</strong></td>
          <td height="25" valign="top" class="bodyText"><form:input type="text" name="password" id="password" path="password"/></td>
        </tr>
        <tr>
          <td height="25" colspan="2" valign="top" >
          <form:errors path="password" cssStyle="color: red;" />
          </td>
        </tr>
        <tr>
          <td height="25" valign="top" class="bodyText"><strong>Confirm password*</strong></td>
          <td height="25" valign="top" class="bodyText"><form:input type="text" name="cpassword" id="cpassword" path="cpassword"/></td>
        </tr>
        <tr>
          <td height="25" colspan="2" valign="top" >
          <form:errors path="cpassword" cssStyle="color: red;" />
          </td>
        </tr>
        <tr>
          <td height="25" valign="top" class="bodyText"><strong>Nick*</strong></td>
          <td height="25" valign="top" class="bodyText"><form:input type="text" name="userName" id="userName" path="userName"/></td>
        </tr>
        <tr>
          <td height="25" colspan="2" valign="top" >
          <form:errors path="userName" cssStyle="color: red;" />
          </td>
        </tr>
        <tr>
          <td height="25" valign="top" class="bodyText"><strong>E-mail</strong></td>
          <td height="25" valign="top" class="bodyText"><form:input type="text" name="email" id="email" path="email"/></td>
        </tr>
        <tr>
          <td height="24" colspan="2" valign="top" >
          <form:errors path="email" cssStyle="color: red;" />
          </td>
        </tr>
        <tr>
          <td height="25" colspan="2" valign="top" class="quote">
            <input type="submit" name="c" id="c" value="send">

          </td>
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


<script>
$(function() {
	//alert("Ready Registration!");
});
function GoLink()
{
	//alert("Hello Registration GoLink!");
}
</script>

</body>
</html>
