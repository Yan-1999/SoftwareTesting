function setCookie(name, value) {
	document.cookie = name + "=" + value + ";path=/";
}

function deleteCookie(name) {
	document.cookie = name + "=" + "" + ";expires=" +
		(new Date(1970, 1, 1)).toUTCString() + ";path=/";
}

function getCookieAll() {
	return document.cookie.split(';');
}

function getCookie(cname) {
	var ca = document.cookie.split(';');
	for (var item of ca) {
		var key_val = item.split('=')
		var key = key_val[0].trim()
		if (key === cname) {
			return key_val[1]
		}
	}
	return "";
}

function getCookieLen() {
	var ca = document.cookie.split(';');
	if (ca[0] === "") {
		return 0;
	}
	return ca.length;
}

var $get = (
	function () {
		var url = window.document.location.href.toString();
		var params = url.split("?");
		if (typeof (params[1]) == "string") {
			params = params[1].split("&");
			var get = {};
			for (var param in params) {
				var val = params[param].split("=");
				get[val[0]] = val[1];
			}
			return get;
		} else {
			return {};
		}
	}
)();
