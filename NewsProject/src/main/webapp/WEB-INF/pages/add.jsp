<%@page contentType="text/html;charset=UTF-8" language="java"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@taglib prefix="form" uri="http://www.springframework.org/tags/form"%>
<%@taglib prefix="spring" uri="http://www.springframework.org/tags"%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Add News</title>
</head>
<body>
	<spring:url value="/news/add" var="url" />
	<form:form action="${url}" method="post" commandName="newsModel">
		<table>
			<tr>
				<td></td>
				<td><form:errors path="title" cssStyle="color: red;" /></td>
			</tr>
			<tr>
				<td><label for="title"><spring:message
							code="news.title" /> </label></td>
				<td><form:input id="title" path="title" /></td>
			</tr>
			<tr>
				<td></td>
				<td><form:errors path="brief" cssStyle="color: red;" /></td>
			</tr>
			<tr>
				<td><label for="brief"><spring:message
							code="news.brief" /></label></td>
				<td><form:input id="brief" path="brief" /></td>
			</tr>
			<tr>
				<td></td>
				<td><form:errors path="content" cssStyle="color: red;" /></td>
			</tr>
			<tr>
				<td><label for="content"><spring:message
							code="news.content" /></label></td>
				<td><form:textarea id="content" path="content" /></td>
			</tr>
		</table>
		<input type="submit" value="<spring:message code="news.add"/>" />
	</form:form>

</body>
</html>