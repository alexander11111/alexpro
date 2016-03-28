<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ page session="false" %>
<html>
<head>
    <!-- <link href="<c:url value="/resources/css/home.css" />" rel="stylesheet">-->
    <link href="http://fonts.googleapis.com/css?family=Rye" rel="stylesheet" type="text/css">
	<title>Home</title>
	<script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
	<style>
	     body {
            background: -webkit-linear-gradient(left, #202022 0%, #7c7c81 50%, #202022 100%);
            background: -moz-linear-gradient(left, #202022 0%, #7c7c81 50%, #202022 100%);
          }
          .header {
            margin: 10px auto;
            width: 98%;
            height: auto;
            /*float: left;*/
            background: -webkit-linear-gradient(top, #202022 0%, #7c7c81 50%, #202022 100%);
            background: -moz-linear-gradient(top, #202022 0%, #7c7c81 50%, #202022 100%);
            border-radius: 10px;
           }
           .header:hover {
                background: -webkit-linear-gradient(top, #7c7c81 0%, #202022 50%, #7c7c81 100%);
                background: -moz-linear-gradient(top, #7c7c81 0%, #202022 50%, #7c7c81 100%);
                color: #7c7c81;
            }
            .header h2:nth-of-type(1) {
                font-family: Rye;
                color: black;
                text-align: center;
                /*border-bottom: 1px solid #211c8e;*/
            }
            h6{
                margin-top: 5px;
                margin-bottom: 5px;
                font-family: Rye;
                color: black;
                text-align: left;
                text-shadow: -2px -2px 10px #f20af5,2px 2px 10px #f20af5;
            }
            .regBox {
            margin: 10px auto;
            width: 98%;
            height: auto;
            display: -webkit-box;
            display: -moz-box;
            -webkit-box-orient: vertical;
            -webkit-box-align: start;
            -moz-box-orient: vertical;
            -moz-box-align: start;
            border-radius: 10px;
            background: -webkit-linear-gradient(top, #202022 0%, #7c7c81 50%, #202022 100%);
            background: -moz-linear-gradient(top, #202022 0%, #7c7c81 50%, #202022 100%);
        }

        .regDiv {
            margin: 10px auto;
            height: auto;
            width: auto;
            border-radius: 20px;
            background: -webkit-linear-gradient(top, #202022 0%, #7c7c81 50%, #202022 100%);
            background: -moz-linear-gradient(top, #202022 0%, #7c7c81 50%, #202022 100%);
            /*-webkit-appearance: button;*/
            -webkit-transition: background 350ms;
            -webkit-box-shadow: 0px 0px 16px 2px black;
            -moz-transition: background 350ms;
            -moz-box-shadow: 0px 0px 16px 2px black;
        }
            .regDiv:hover {
                background: -webkit-linear-gradient(top, #7c7c81 0%, #202022 50%, #7c7c81 100%);
                background: -moz-linear-gradient(top, #7c7c81 0%, #202022 50%, #7c7c81 100%);
                color: #7c7c81;
                text-shadow: -2px -2px 10px #f20af5,2px 2px 10px #f20af5;
                -webkit-box-shadow: 0px 0px 16px 2px #f20af5;
                -moz-box-shadow: 0px 0px 16px 2px #f20af5;
                cursor: pointer;
            }
            .regDiv h3 {
                font-family: Rye;
                color: black;
                text-align: center;
                padding-left: 20px;
                padding-right: 20px;
                /*border-bottom: 1px solid #211c8e;*/
            }
        input[type="text"]{
             font-family: Rye;
             color: black;
             text-align: center;
             border-bottom: 1px solid #211c8e;
        }
        
	</style>
	<script type="text/javascript">
	var oper = {operation: "null"};
    function doAjax() {
      	//alert("Message:"+$('#idOperation').val());
      $.ajax({
    	  contentType: "application/json",
          type: "POST",
          url: 'CommandServlet',
          data: StrToJSON(),
          success: function(data) {
            oper = JSON.parse(data);
            $('#idResult').append("<h6>Result:"+oper.operation+"</h6>");
        }
      });
    }
    function StrToJSON() {
    	return JSON.stringify({"operation": $('#idOperation').val(),});
    	}
  </script>
	
</head>
<body>
    <div class="header">
        <h2>Home Work</h2>
    </div>
     <div class="regBox">
        <div class="regDiv" onclick="doAjax()">
            <h3>Send Command</h3>
        </div>
        <div class="regDiv" >
            <input id="idOperation" type="text" name="operation" value="ring"/>
        </div>
    </div>
    <div id="idResult" class="regBox">
        
    </div>
    
</body>
</html>
