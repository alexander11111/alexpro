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
<spring:url value="/resources/css/mm_health_nutr.css" var="urlCss" />
<spring:url value="/resources/css/mm_product_lg.gif" var="urlUser" />
<link rel="stylesheet" href="${urlCss}" type="text/css" />
<script language="javascript">
var d=new Date();
var monthname=new Array("January","February","March","April","May","June","July","August","September","October","November","December");
var TODAY = monthname[d.getMonth()] + " " + d.getDate() + ", " + d.getFullYear();
</script>
<body bgcolor="#F4FFE4">
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr bgcolor="#D5EDB3">
    <td colspan="2" rowspan="2"><img src="${urlPic}" alt="Header image" width="382" height="101" border="0" /></td>
    <td width="588" height="50" id="logo" valign="bottom" align="center" nowrap="nowrap">ALEXSoft Company</td>
    <td width="141">&nbsp;</td>
  </tr>

  <tr bgcolor="#D5EDB3">
    <td height="51" align="center" valign="top" bgcolor="#D5EDB3" id="tagline">News Information</td>
	<td width="141"><table width="200" border="0">
	  <tr>
	    <td width="33" class="navText"><strong><strong><spring:message code="user.username" /></strong></td>
	    <td width="93" class="navText" ><strong id="lbuser">Undefined</strong></td>
	    </tr>
    </table></td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#5C743D"><img src="css/mm_spacer.gif" alt="" width="1" height="2" border="0" /></td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#99CC66" background="css/mm_dashed_line.gif"><img src="css/mm_dashed_line.gif" alt="line decor" width="4" height="3" border="0" /></td>
  </tr>

  <tr bgcolor="#99CC66">
  <td>&nbsp;</td>
  	<td colspan="3" id="dateformat" height="20"><a href="javascript:;">HOME</a>&nbsp;&nbsp;::&nbsp;&nbsp;<script language="JavaScript" type="text/javascript">
      document.write(TODAY);	</script>	</td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#99CC66" background="css/mm_dashed_line.gif"><img src="css/mm_dashed_line.gif" alt="line decor" width="4" height="3" border="0" /></td>
  </tr>

  <tr>
    <td colspan="4" bgcolor="#5C743D"><img src="css/mm_spacer.gif" alt="" width="1" height="2" border="0" /></td>
  </tr>
 <tr>
    <td width="40" height="291">&nbsp;</td>
    <td colspan="2" valign="top">&nbsp;<br />
      <table border="0" cellspacing="0" cellpadding="2" width="931" id="NewsTable">
        <tr>
           <td colspan="3"><a href="javascript:;" class="pageName">USER NEWS</a></td>
		</tr>
        <tr>
          <td width="673" class="pageName_m">${news.title}</td>
        </tr>
        <tr>
          <td class="smallText"><p>${news.content}</p>		  
          </td>
        </tr>
        <tr>
          <td height="42" colspan="2" bgcolor="#99CC66" id="dateformat"><table width="928" border="0">
              <tr class="navText">
                <td width="53">Author:</td>
                <td width="180">${news.author.userName}</td>
                <td width="49">Dater:</td>
                <td width="387">${news.strcreated}</td>
                <td width="59"><p>News ID</p></td>
                <td width="86">${news.newsId}</td>
                <td width="84"><a href="javascript:;" onClick="delNews('${news.author.userName}','${news.newsId}')"><strong id="lbDelNews">delete</strong></a></td>
              </tr>
          </table></td>
	    </tr>
      </table>      
      <p>&nbsp;</p>
      
      <table width="929" border="0" id="CommentTabl">
        <tr>
          <td colspan="3"><a href="javascript:;" class="pageName">USER COMMENT</a></td>
		  </tr>
          <tr>
            <td width="51" bgcolor="#99CC66"><strong>User</strong></td>
          <td bgcolor="#99CC66">UserXX</td>
          <td bgcolor="#99CC66">&nbsp;</td>
          <td width="73" bgcolor="#99CC66" class="navText">Comment ID</td>
          <td width="38" bgcolor="#99CC66" class="navText">CID</td>
          <td width="66" bgcolor="#99CC66" class="navText"><a href="javascript:;">delcomm</a></td>
          </tr>
        <tr>
          <td colspan="6" class="navText">Text Comment Message</td>
        </tr>
        <tr class="navText">
          <td bgcolor="#D5EDB3"><strong>Created</strong></td>
          <td width="272" bgcolor="#D5EDB3">Comm Date Created</td>
          <td width="403" bgcolor="#D5EDB3">&nbsp;</td>
          <td colspan="3" bgcolor="#D5EDB3">&nbsp;</td>
        </tr>
        <tr>
          <td colspan="6">&nbsp;</td>
        </tr>
      </table>
      

      <table width="929" height="195" border="0" cellpadding="2" cellspacing="0" id="NewsTable2">
        <tr>
          <td width="118" height="22" class="pageName_m">&nbsp;</td>
          <td height="22" class="pageName_m"><a href="javascript:;" class="pageName">ADD YOUR COMMENT</a></td>
        </tr>
        <tr>
          <td height="20" class="navText"><span class="navText"><strong>E-mail</strong></span></td>
          <td height="20" class="navText"><span class="navText">
            <input name="email" type="text" class="navText" id="email">
          </span></td>
        </tr>
        <tr>
          <td height="24" class="navText"><span class="navText"><strong>Password</strong></span></td>
          <td height="24" class="navText"><span class="navText">
            <input name="password" type="password" class="navText" id="password">
          </span></td>
        </tr>
        <tr>
          <td height="152" rowspan="2" class="navText"><span class="navText"><strong>Comment</strong></span></td>
          <td height="78" class="navText"><span class="navText">
            <textarea name="comment" cols="65" rows="7" class="navText" id="comment"></textarea>
            </span></td>
        </tr>
        <tr>
          <td height="28" class="smallText"><span class="navText">
            <input type="button" name="send" id="send" value="Send" onClick="addComment();">            
       
            </span></td>
        </tr>
      </table>
      <p><br />
    </p>
    <p>&nbsp; </p></td>
    <td width="141">&nbsp;</td>
  </tr>

 <tr>
    <td width="40">&nbsp;</td>
    <td width="342">&nbsp;</td>
    <td width="588">&nbsp;</td>
	<td width="141">&nbsp;</td>
  </tr>
</table>




<spring:url value="/addComment" var="urlComment" />
<spring:url value="/updateNewsData" var="urlupdateNewsData" />
<spring:url value="/deleteNews" var="urldelNews" />
<spring:url value="/deleteComment" var="urldelComment" />
<script>
function addComment()
{
	//alert("Send addComment email:"+$('#email').val()+" password:"+$('#password').val()+" comment:"+$('#comment').val());
    $.ajax({
    dataType: "json",
    type: "POST",
    url: "${urlComment}",
    data :  {
			"email" : $('#email').val(),
			"password" : $('#password').val(),
			"comment" : $('#comment').val()
    },
    success: function(data){ //strcreated
    	if (data.savestate==0) {alert("addComment Ok!="+data.savestate);
    	    printComment(data.userName,data.newsId,$('#comment').val(),data.strcreated,data.commentId);
    	}
    	if (data.savestate==1) alert("Error User Not Fount!");
    	if (data.savestate==2) alert("Error Save To Data Base!");
    },
    error: function(e){
        //alert("addComment Error!: " + e);
    }
});
}
function delNews(userName,newsID)
{
	//alert("delNews : NewsAuthor="+userName+" User:${user.userName} News ID:" + newsID);
    $.ajax({
	dataType: "json",
    type: "POST",
    url: "${urldelNews}/"+userName+"/"+newsID,
    data : {
			"newsID" : newsID,
			"userName" : userName
		},
    success: function(data){
    	if (data.param0==0) alert("Delete News Ok");else
    	if (data.param0==1) alert("Delete News Error! User Not Found.");else
    	if (data.param0==2) alert("Delete News Error!");else
    	if (data.param0==3) alert("Delete News Error! User Failed!");
    },
    error: function(e){
    	alert("Delete News Ok e"); 
        //alert('Delete Error: ' + e);
    }
});
}

function loadNews() {
	//checkLogin();
	//alert('NEWS:loadNews : ');
	$.getJSON("${urlupdateNewsData}", function(data) {
		//alert('NEWS:loadNews OK!: ');
		$("#CommentTabl").empty();
		//$("#CommentTabl").append(
		//		  "<tr class='navText'>"+
		//          "<tr>"+
		//           "<td colspan='3'><a href='javascript:;' class='pageName'>USER COMMENT</a></td>"+
		//		  "</tr>"
		//		  );
		$.each(data.comments, function(idx, obj) {
			//alert('NEWS:Comment : '+obj.message);
			printComment(obj.author.userName,data.newsId,obj.message,obj.strcreated,obj.commentId);
		});		
		
	});
}
function OnClickDel(userName)
{
	alert("OnClickDel:"+userName);

}
function delComment(commentId)
{
	userName = 'Alex';
	//alert("delComment : CommAuthor="+userName+" User:${user.userName} Comment ID:" + commentId);
    $.ajax({
	dataType: "json",
    type: "POST",
    url: "${urldelComment}/"+userName+"/"+commentId,
    data : {
			"commentId" : commentId,
			"userName" : userName
		},
    success: function(data){
    	if (data.param0==0) alert("Delete Comment Ok");else
    	if (data.param0==1) alert("Delete Comment Error! User Not Found.");else
    	if (data.param0==2) alert("Delete Comment Error!");
    },
    error: function(e){
        //alert('Delete Error: ' + e);
    }
});
}
function printComment(userName,newsId,message,strcreated,commentId) {
    //strClick = "onClick=OnClickDel(\''.$id.\'');";        
	if ("${isAutorized}"==0) str="<td width='66' bgcolor='#99CC66' class='navText'><a href='javascript:;'></a></td>";else
	if ("${isAutorized}"==1) str="<td width='66' bgcolor='#99CC66' class='navText'><a href='javascript:;' onclick='delComment("+commentId+");' >delcomm</a></td>";
	$("#CommentTabl").append(
			  "<tr class='navText'>"+
	          //"<tr>"+
	          // "<td colspan='3"><a href='javascript:;' class='pageName'>USER COMMENT</a></td>"+
			  //"</tr>"+
            "<td width='51' bgcolor='#99CC66'><strong>User</strong></td>"+
            "<td bgcolor='#99CC66'>"+userName+"</td>"+
            "<td bgcolor='#99CC66'>&nbsp;</td>"+
            "<td width='73' bgcolor='#99CC66' class='navText'>Comment ID</td>"+
            "<td width='38' bgcolor='#99CC66' class='navText'>"+commentId+"</td>"+
            str+
	        "</tr>"+
	        "<tr>"+
	          "<td colspan='5' class='navText'>"+message+"</td>"+
	        "</tr>"+
	        "<tr class='navText'>"+
	          "<td bgcolor='#D5EDB3'><strong>Created</strong></td>"+
	          "<td width='272' bgcolor='#D5EDB3'>"+strcreated+"</td>"+
	          "<td width='403' bgcolor='#D5EDB3'>&nbsp;</td>"+
	          "<td colspan='3' bgcolor='#D5EDB3'>&nbsp;</td>"+
	        "</tr>"+
	        "<tr>"+
	          "<td colspan='6'>&nbsp;</td>"+
	        "</tr>"
	);	
}
$(function(){
	//alert("News function! "+"${user.userName}"+"Autotized:"+"${isAutorized}");
	
	if ("${isAutorized}"==0){
	 $("#lbuser").replaceWith("<strong id='lbuser'>Undefined</strong>");
	 $("#lbDelNews").replaceWith("<strong id='lbDelNews'></strong>");
	}
	else{
	 $("#lbDelNews").replaceWith("<strong id='lbDelNews'>delete</strong>");
	 $("#lbuser").replaceWith("<strong id='lbuser'>${user.userName}</strong>");
	}
	

	loadNews();
});
</script>
</body>
</html>
