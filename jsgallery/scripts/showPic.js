window.onload = prepareGallery;
function showPic(whichpic) {
        if (!document.getElementById("placeholder")) return true;
        var source = whichpic.getAttribute("href");
        var placeholder = document.getElementById("placeholder");
        placeholder.setAttribute("src", source);
        if (!document.getElementById("description")) return false;
        var text = whichpic.getAttribute("title");
        var description = document.getElementById("description");
        description.firstChild.nodeValue = text;
        return false;
}

function prepareGallery() {
        if (!document.getElementById) return false;
        if (!document.getElementsByTagName) return false;
        if (!document.getElementById("iamgeGallery")) return false;
        var gallery = getElementById("imagegallery");
}
