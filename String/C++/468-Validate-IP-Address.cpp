class Solution {
public:
    vector<string> split(string IP, char ch){
        vector<string> items;
        for(int i = 0; i < IP.size(); i++){
            int j = i;
            string item;
            while(j < IP.size() && IP[j] != ch) item += IP[j++];
            i = j;
            items.push_back(item);
        }
        return items;
    }

    /*
    1.ipv4有四组，每组的slice无前导零，只包含数字，且每个slice的范围在0~255
    2.ipv6有八组，每组最多四个字符，可以是数字或大小写字母，可以包含前导零，可以允许slice只是一个0
    */
    string validIPAddress(string IP) {
        if(IP.find('.') == -1 && IP.find(':') == -1) return "Neither";
        if(IP.find('.') != -1) return check_ipv4(IP);
        if(IP.find(':') != -1) return check_ipv6(IP);
        return "Neither";
    }
    
    string check_ipv4(string ip){
        auto items = split(ip , '.');
        if(ip[ip.size() - 1] == '.') items.push_back("");
        if(items.size() != 4) return "Neither";
        for(auto item : items){
            /*如果slice为空或数字个数大于三位数*/
            if(item.empty() || item.size() > 3) return "Neither";
            /*含有前导零*/
            if(item.size() > 1 && item[0] == '0') return "Neither";
            /*slice里的字符不合法*/
            for(char ch : item){
                if(ch < '0' || ch > '9') return "Neither";
            }
            /*slice代表的数字太大*/
            int num = stoi(item);
            if(num > 255) return "Neither";
        }
        return "IPv4";
    }

    string check_ipv6(string ip){
        auto items = split(ip, ':');
         if(ip[ip.size() - 1] == ':') items.push_back("");
        cout<<items.size()<<endl;
        if(items.size() != 8) return "Neither";
        for(auto item : items){
            if(item.empty() || item.size() > 4) return "Neither";
            for(char ch : item){
                if(!check(ch)) return "Neither";
            }
        }
        return "IPv6";
    }

    bool check(char ch){
        if(ch >= '0' && ch <= '9') return true;
        if(ch >= 'a' && ch <= 'f') return true;
        if(ch >= 'A' && ch <= 'F') return true;//16进制最大是F
        return false; 
    }
    

};