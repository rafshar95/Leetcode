class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        while(num >= 1000){
            num -= 1000;
            res += 'M';
        }
        if(num >= 900){
            num -= 900;
            res += "CM";
        }
        if(num >= 500){
            num -= 500;
            res += 'D';
        }
        if(num >= 400){
            num -= 400;
            res += "CD";
        }
        while(num >= 100){
            num -= 100;
            res += 'C';
        }
        if(num >= 90){
            num -= 90;
            res += "XC";
        }
        if(num >= 50){
            num -= 50;
            res += 'L';
        }
        if(num >= 40){
            num -= 40;
            res += "XL";
        }
        while(num >= 10){
            num -= 10;
            res += 'X';
        }
        if(num >= 9){
            num -= 9;
            res += "IX";
        }
        if(num >= 5){
            res += 'V';
            num -= 5;
        }
        if(num >= 4){
            res += "IV";
            num -= 4;
        }
        while(num >= 1){
            res += "I";
            num--;
        }
        return res;
    }
};
