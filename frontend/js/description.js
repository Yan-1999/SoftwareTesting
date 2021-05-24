function AddToSuite(elem) {
	var test = elem.getAttribute("id");
	var suit_count_elem = document.getElementById("suite-count");
	var count = parseInt(suit_count_elem.textContent);
	if (getCookie(test)) {
		deleteCookie(test);
		count--;
		elem.value = "加入测试套件";
	}
	else {
		setCookie(test, "true");
		count++;
		elem.value = "移出测试套件";
	}
	suit_count_elem.innerText = count.toString();
}
