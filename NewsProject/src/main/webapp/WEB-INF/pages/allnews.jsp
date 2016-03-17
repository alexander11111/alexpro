<%@page contentType="text/html;charset=UTF-8" language="java"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@taglib prefix="spring" uri="http://www.springframework.org/tags"%>
<%@taglib prefix="form" uri="http://www.springframework.org/tags/form"%>
<html>
<head>
<title>Home Page</title>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<link href="../../resources/css/mm_health_nutr.css" rel="stylesheet" type="text/css">
</head>
<script type="text/javascript" src="<c:url value="/resources/js/jquery-1.10.2.min.js"/>"></script>
<script type="text/javascript" src="<c:url value="/resources/js/script.js"/>"></script>
<spring:url value="/resources/css/mm_health_photo.jpg" var="urlPic" />
<spring:url value="/resources/css/mm_spacer.gif" var="urlPSpacer" />
<spring:url value="/resources/css/mm_dashed_line.gif" var="urlPline" />

<spring:url value="/resources/css/mm_health_nutr.css" var="urlCss" />


<link rel="stylesheet" href="${urlCss}" type="text/css" />
<script language="javascript">
var d=new Date();
var curentCategory=0;
var isLogin=0;
var monthname=new Array("January","February","March","April","May","June","July","August","September","October","November","December");
var TODAY = monthname[d.getMonth()] + " " + d.getDate() + ", " + d.getFullYear();
</script>

<body bgcolor="#F4FFE4">
<spring:url value="/userRegistr" var="urlRegs" />
<spring:url value="/newsAddReflect" var="urlNewsAdd" />
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr bgcolor="#D5EDB3">
    <td colspan="3" rowspan="2"><img src="${urlPic}" alt="Header image" width="382" height="101" border="0"></td>
    <td height="51" colspan="3" align="center" valign="bottom" nowrap bgcolor="#D5EDB3" id="logo">ALEXSoft Company</td>
    </td>
    <td colspan="5" rowspan="2"><table width="242" border="0">
      <tr>
        <td class="navText"><strong id="lblog"><spring:message code="user.login" /></strong></td>
          <td colspan="2"><label for="login" ></label>
          <input type="text" name="login" id="login"></td>
        </tr>
      <tr>
        <td class="navText"><strong id="lbpass"><spring:message code="user.password" /></strong></td>
        <td colspan="2">
        <input type="password" name="password" id="password"></td>
        </tr>
      <tr> 
        <td class="navText"><strong><spring:message code="user.username" /></strong></td>
        <td colspan="2" class="navText"><strong id="lbuser">UserXX</strong></td>
        </tr>
      <tr>
        <td width="73"><a href="javascript:;" onClick="OnLogin();" class="navText"><strong>Login</strong></a></td>
        <td width="81"><a href="${urlRegs}" class="navText"><strong>Registration</strong></a></td>
        <td width="66"><a href="javascript:;" onClick="OnExit();"  class="navText"><strong>Exit</strong></a></td>
      </tr>
    </table></td>
  </tr>
  <tr bgcolor="#D5EDB3">
    <td height="47" colspan="3" align="center" valign="top"  id="tagline2">THE LATEST NEWS</td>
  </tr>
  <tr>
    <td colspan="11" bgcolor="#5C743D"><img src="${urlPSpacer}" alt="" width="1" height="2" border="0"></td>
  </tr>

  <tr>
    <td colspan="11" bgcolor="#99CC66" background="${urlPline}"><img src="${urlPline}" alt="line decor" width="4" height="3" border="0"></td>
  </tr>

  <tr bgcolor="#99CC66">
  	<td height="20" colspan="8" bgcolor="#99CC66" id="dateformat">&nbsp;&nbsp;
  	<script language="javascript"> document.write(TODAY);	</script>	
  	</td>
  	<td width="159" height="20" bgcolor="#99CC66" id="dateformat"><a href=${urlNewsAdd} id="addNewsButt" class="navText" "><strong>Add news</strong></a></td>
  	<td width="44" bgcolor="#99CC66" id="dateformat"><a href="?lang=en"><spring:message code="en" /></a></td>
  	<td width="37" height="20" bgcolor="#99CC66" id="dateformat"><a href="?lang=ru"><spring:message code="ru" /></a></td>
  </tr>
  <tr>
    <td colspan="11" bgcolor="#99CC66" background="${urlPline}"><img src="${urlPline}" alt="line decor" width="4" height="3" border="0"></td>
  </tr>

  <tr>
    <td colspan="11" bgcolor="#5C743D"><img src="${urlPSpacer}" alt="" width="1" height="2" border="0"></td>
  </tr>

 <tr>
    <td width="175" valign="top" bgcolor="#5C743D">
	<table border="0" cellspacing="0" cellpadding="0" width="165" id="navigation">
        <tr>
          <td width="165">&nbsp;<br>
		 &nbsp;<br></td>
        </tr>
        <tr>
          <td width="165"><a href="javascript:;" onClick="loadAllNews(0);" class="navText">politics</a></td>
        </tr>
        <tr>
          <td width="165"><a href="javascript:;" onClick="loadAllNews(1);" class="navText">events</a></td>
        </tr>
        <tr>
          <td width="165"><a href="javascript:;" onClick="loadAllNews(2);" class="navText">sport</a></td>
        </tr>
        <tr>
          <td width="165"><a href="javascript:;" onClick="loadAllNews(3);" class="navText">auto</a></td>
        </tr>
        <tr>
          <td width="165"><a href="javascript:;" onClick="loadAllNews(4);" class="navText">other</a></td>
        </tr>
      </table>
 	В <br>
  	&nbsp;<br>
  	&nbsp;<br>
  	&nbsp;<br> 	</td>
    <td width="53"><img src="${urlPSpacer}" alt="" width="50" height="1" border="0"></td>
    <td colspan="2" valign="top"><img src="${urlPSpacer}" alt="" width="305" height="1" border="0"><br>
	&nbsp;<br>
	&nbsp;<br>
	 <div id="NewsBlock">
	    <table width="634" id="NewsTable" border="0">
        <tr>
          <td colspan="3"><a href="javascript:;" class="pageName_m">WELCOME MESSAGE</a></td>
		</tr>
		<tr>
          <td colspan="3" >
          <p class="smallText">&nbsp;</p>
		  </td>
        </tr>
      </table>
     </div> 
      
      
	
    <td width="4">&nbsp;</td>
        <td width="6" valign="top"><br>
	  &nbsp;	</td>
	<td colspan="5"><br>
      <table border="0" cellspacing="0" cellpadding="0" width="190" id="leftcol2">
        <tr>
          <td width="16"><img src="${urlPSpacer}" alt="" width="10" height="1" border="0"></td>
          <td width="153" class="smallText"><br>
            <p><span class="subHeader">TITLE HERE</span><br>
              Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam. </p>
            <p><span class="subHeader">TITLE HERE</span><br>
              Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam. </p>
            <p><span class="subHeader">TITLE HERE</span><br>
              Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam. </p>
            <br>
            &nbsp;<br></td>
          <td width="21">&nbsp;</td>
        </tr>
    </table></td>
  </tr>
  <tr>

    <td width="175">&nbsp;</td>
    <td width="53">&nbsp;</td>
    <td width="154">&nbsp;</td>
    <td width="480">&nbsp;</td>
    <td width="4">&nbsp;</td>
    <td width="6">&nbsp;</td>
	<td colspan="5">&nbsp;</td>
  </tr>
</table>






<spring:url value="/list1" var="urlAjax" />
<spring:url value="/newsOneView" var="urlOneNews" />
<spring:url value="/userLogin" var="urlLogin" />
<spring:url value="/userUnLogin" var="urlUnLogin" />
<spring:url value="/checkLogin" var="urlCheckLogin" />
<spring:url value="/regs" var="urlReg1" />	
<script>
function loadAllNews(category) {
	curentCategory = category 
	//checkLogin();
	//alert('loadAllNews curentCategory: '+curentCategory);
	$.getJSON("${urlAjax}/"+category, function(data) {
		//alert('loadList1 DATA:');
		$("#NewsTable").empty();
		$.each(data, function(idx, obj) {
			str="";
			//if ("${isAutorized}"==0) str="";else
			//if ("${isAutorized}"==1) 
				//str="<a href=javascript:; onclick='delNews("+obj.newsId+");'>Del news</a>"; 
			$("#NewsTable").append(
					//"<div id='news_"+obj.newsId+"'>"+
					"<tr>"+
			          "<td width='436'><a href="+'${urlOneNews}'+"/"+obj.newsId+" class='pageName_m'>"+obj.title+"</a></td>"+
			        "</tr>"+
					"<tr>"+
			          "<td colspan='3'>"+
			          "<p class='smallText'>"+obj.brief+"...</p>"+
					  "</td>"+
			        "</tr>"+
					"<tr>"+
				      "<td height='15' bgcolor='#99CC66' id='dateformat'>"+
				      "Date:"+obj.strcreated+
				      "</td>"+
  	                   "<td width='95' height='15' bgcolor='#99CC66' id='dateformat'>"+
  	                 str+
			           "</td>"+
				    "</tr>  <tr><td> </td></tr>"
			           //</div>

			);
		});		
		
	});
}







function OnLogin()
{
    $.ajax({
	dataType: "json",
    type: "POST",
    url: "${urlLogin}/",
    data : {
			"login" : $('#login').val(),
			"password" : $('#password').val()
		},
    success: function(data){
    	//alert("Login Ok!="+data.userName);
    	//alert("OnLogin Ok!=User "+data.userName + " Autorised:"+data.isAutorized);
    	hideElement(data.isAutorized,data.userName);
    },
    error: function(e){
        //alert('Error: ' + e);
    	hideElement(0);
    }
});
}

function OnExit(){
    //alert("Exit Session: ");
    $.ajax({
    type: "POST",
    url: "${urlUnLogin}",
    data : "newsID=0",
    success: function(data){
    	hideElement(0,"Undefined");
    	//alert("Session Deleted OK");
    },
    error: function(e){
        //alert('Error: Dlete News' + e);
    }
});
      	$("#login").show("fast");
       	$("#password").show("fast");
    	$("#lblog").show("fast");
    	$("#lbpass").show("fast");
}
function hideElement(isAutorized,userName){
	//alert("hideElement: isAutorized:"+isAutorized+" SUser: ${user.userName}"+" IsAutor: ${isAutorized}");
	if (isAutorized==1){
		$("#login").hide("fast");
    	$("#password").hide("fast");
    	$("#lblog").hide("fast");
    	$("#lbpass").hide("fast");
    	$("#lbuser").replaceWith("<strong id='lbuser'>"+userName+"</strong>");
    	$("#addNewsButt").show("fast");
    	//$("#delNewsID").show("fast");
	}else
	if ((isAutorized==0)||(isAutorized==null)){
		$("#login").show("fast");
       	$("#password").show("fast");
    	$("#lblog").show("fast");
    	$("#lbpass").show("fast");
    	$("#addNewsButt").hide("fast");
    	$("#lbuser").replaceWith("<strong id='lbuser'>Undefined</strong>");
    	//$("#delNewsID").hide("fast");
	}
}
$(function(){
	//alert("News function!");
	//checkLogin();
	loadAllNews(curentCategory);
	hideElement("${isAutorized}","${user.userName}");
});

</script>

</body>
</html>