$(function() {
	$("#send").click(add);
	//loadList();
});

function loadList1() {
	alert('loadList:');
	$.ajax({
		type : "POST",
		url : "/welcome",
		dataType: "json",
		cache : false,
		success : function(response) {
			alert('REST:'+response);
		}
	});
	return false;
}
function loadList() {

}

function add() {
	var author = $("#author").val();
	var message = $("#message").val();
	$.ajax({
		type : "POST",
		url : "/list",
		data : {
			"author" : author,
			"message" : message
		},
		cache : false,
		success : function(response) {
			var messageResp = new Array('Комментарий добавлен',
					'Комментарий не добавлен. Ошибка базы данных',
					'Нельзя добавлять пустые комментарии');
			var resultStat = messageResp[Number(response)];
			if (response == 0) {
				$("#author").val("");
				$("#message").val("");
				$("#commentBlock").append(
						"<div class='comment'>Автор: <strong>" + author
								+ "</strong><br>" + message + "</div>");

			}
			$("#resp").text(resultStat).show().delay(1500).fadeOut(800);

		}
	});
	return false;
}
