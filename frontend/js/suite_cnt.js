function SuiteCnt() {
    var suit_count_elem = document.getElementById("suite-count");
    suit_count_elem.textContent = getCookieLen().toString();
}

SuiteCnt();
