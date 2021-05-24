function Suite() {
    var ca = getCookieAll();
    var table = document.getElementById('product-info');
    for (const data of ca) {
        var test = data.split('=')[0].split(':');
        var tr = document.createElement('tr');
        for (const attr of test) {
            var td = document.createElement('td');
            td.innerText = attr;
            tr.appendChild(td);
        }
        table.appendChild(tr);
    }
}

Suite();
