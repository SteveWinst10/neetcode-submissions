class Solution {

    public String encode(List<String> strs) {
    StringBuilder encodedStr = new StringBuilder();
    for(String str : strs){
        encodedStr.append(str).append("\0");
    }
    return encodedStr.toString();
}

public List<String> decode(String str) {
    StringBuilder curString = new StringBuilder();
    List<String> result = new ArrayList<>();
    for(Character chr: str.toCharArray()){
        if(chr == '\0'){
            result.add(curString.toString());
            curString = new StringBuilder();
        }
        else{
            curString.append(chr);
        }
    }
    return result;
}
}
