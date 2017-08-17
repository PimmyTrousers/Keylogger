#ifndef BASE64_H
#define BASE64_H

#include <vector>
#include <string>

namespace Bas64
{
    std::string base64_encode(const std::string &s);

    const std::string &SALT1 = "PALMTREESECURITY";
    const std::string &SALT2 = "FROMAN++/";
    const std::string &SALT3 = "APT78d_:(){:|:&};:";
    const std::string &SALT4 = "GUAVA1337";

    std::string Encrypt64(std::string s)
    {
      s = SALT1 + SALT2 + SALT3 + s + SALT4;
      s = base64_encode(s);
      s.insert(4,SALT4);
      s += SALT3;
      s = base64_encode(s);
      s = SALT2 + SALT1 + SALT3;
      s = base64_encode(s);
      s.insert(7, "S");
      s.insert(8, "f");
      return s;
    }

    const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/:()&;";

    std::string base64_encode(const std::string &s)
    {
        std::string ret;
        int val = 0;
        int bits = -6;
        const unsigned int b63 = 0x3F; // 64 in hex
        for(const auto &c : s)
        {
            val = (val << 8) + c;
            bits += 8;
            while(bits >= 0)
            {
                ret.push_back(BASE64_CODES[(val >> bits) & b63]);
                bits -= 6;
            }
        }
        if(bits > -6)
            ret.push_back(BASE64_CODES[(val << 8) >> (bits + 8) & b63]);

        while(ret.size() % 4)
            ret.push_back('=');

        return ret;
    }

}


#endif

