#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <memory>

using namespace std;

template<typename T>
class TrieNode{
public:
    TrieNode() = default;
    TrieNode(T val):val(val){};

    T val;
    bool leaf;
    unordered_map<T, unique_ptr<TrieNode<T>>> children;
};

template<typename T>
class Trie{
public:
    Trie():root{make_unique<TrieNode<T>>()} {}

    bool insert(string word)
    {
        bool new_substring=false;
        TrieNode<T>* current=root.get();
        for(const auto& c:word){
            if(current->children.find(c)==current->children.end()){
                current->children[c]= make_unique<TrieNode<T>>(c);
                new_substring=true;
            }
            current = current->children[c].get();
        }
        current->leaf=true;

        return new_substring;
    }

    unique_ptr<TrieNode<T>> search(string word)
    {
        unique_ptr<TrieNode<T>> current=root.get();
        for(const auto& c:word){
            if(current->children.find(c)==current->children.end()){
                return nullptr;
            } else {
                current=current->children[c];
            }
        }
        return current;
    }
private:
    unique_ptr<TrieNode<T>> root;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res=0;
        sort(words.begin(), words.end());
        auto last = unique(words.begin(), words.end());
        words.erase(last, words.end()); //no need to keep duplicate
        sort(words.begin(), words.end(),[](const auto& a, const auto& b){
          return a.size()>b.size(); //decreasing order
        });

        Trie<char> trie;
        for(const auto& word:words){
            string s=word;
            reverse(s.begin(), s.end()); //check subfix
            bool new_substring = trie.insert(s);
            if(new_substring){
                res+=word.size()+1;
            }
        }
        return res;
    }
};

namespace n_square_Solution{
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<string> inside;
//        sort(words.begin(), words.end(),[](const auto& a, const auto& b){
//            return a.size()<b.size();
//        });


        sort(words.begin(), words.end());
        auto last = unique(words.begin(), words.end());
        words.erase(last, words.end()); //no need to keep duplicate


//        for(const auto& elem1:words){
//            for(const auto& elem2:words){
//                int pos=elem2.rfind(elem1); //import to search "backward", ["ctxdic","c"]

//                vector<string> matches;
//                if (elem1!=elem2 && pos != string::npos
//                        && pos+elem1.size()==elem2.size()){
//                    inside.push_back(elem1);
//                    break; //["time", "atime", "btime"]
////                    matches.push_back(elem2);
////                    cout << elem2 << endl;
//                }
//            }
//        }

        for(int i=0;i<words.size();++i){
            for(int j=i+1;j<words.size();++j){
                int pos=words[j].rfind(words[i]);
                if (pos != string::npos
                        && pos+words[i].size()==words[j].size()){
                    inside.push_back(words[i]);
                    break; //["time", "atime", "btime"]
                }
            }
        }

        int c_count=0;
        for(const auto& elem:words){
            c_count+=elem.size();
        }

        int inside_count=0;
        for(const auto& elem:inside){
            inside_count+=elem.size();
        }
        int pound_sign = words.size() - inside.size();

        int final=c_count-inside_count+pound_sign;
        return final;
    }
};
}

int main()
{
    TrieNode<char> tNode;

    //        trie.search("me");
    //        trie.search("time");
    //        trie.search("bell");
    vector<string> v;

    Solution s;

    v = vector<string>{"t"};



    //output: 1341
    //expected: 13935
    v = vector<string>{"gtgwzg","bgmwmrk","nqslwdi","nwsfvi","ixfez","muovikm","cfxptlx","nffdyw","zrmtvv","odmhe","btupmf","sjfmx","pytwab","kznqxp","jngry","ppivkj","bwwmqpq","lxbnu","altks","motdd","jimgy","lppjek","kbanc","lxtgvb","uqvvek","ntpxnyn","qlrdcx","xcmgzwt","gtcapjg","sntqu","tkfwow","xqbja","fyqbiw","ruawk","frjdyp","txknwrh","kzyjg","bttxz","lgntv","ewfxgz","lchzsg","yqfoa","zhsbm","htxcg","qjqkxou","gkcxv","lhsjs","igrtnjv","ifuecww","slzcs","yceue","retyxs","klybm","jbxjv","erhosw","bjhjpjr","nvwkcq","mezursm","ykbvin","xzlij","uiopt","zyuxddz","rmfhp","xfltr","csluqps","gzuvj","oyqyjy","lgjuw","hytegp","gkoxj","boirzbg","dsqre","gxrgabo","jdlab","kchijrb","kuozwmp","vrjqov","hfmehfl","xkonfn","yfhkp","ocota","akfao","qllffp","etrpndt","nrnmeh","kaemhl","diqeja","wxclkjl","bggfny","krvmmx","wofbj","dliqwvn","fcihtkt","fonqx","irawity","kkmlx","gjmshvq","llcov","vyqbaz","ypprher","erzcn","zdzmj","secthxg","dnyxtvn","ivqrk","xzstj","tvmepa","rweifqm","tjvoeme","lquuq","xeulv","gxmyfrx","ahltke","hgbgr","gtddmv","dbrol","tmqlk","bmfaok","iqojj","zowni","gwkvkgs","mtoxm","wyinnug","kfotoix","duymz","keywrvl","mukloly","lfcycan","illypju","jfmlw","atmaai","lcsrk","aarsej","gylent","cvoorpa","awpczi","vsrerd","gngvhu","fhwkc","wsvftqb","yevwb","vgcpwb","zymvkkh","bziergz","regjz","ajhdn","bgqwre","kqfqax","cjyly","vinwbe","ymkbtst","oavwn","onjzg","qssxa","eiakw","zpcke","ifgotsq","adjdprf","ilbtt","vcjgw","zzbjnin","nztco","dbyruh","nvsvk","jgits","erzqz","leqns","twrrlp","rqymf","vmzijn","kegnmyk","oqbmcg","otzae","wtnls","gstgfvy","pqcjlui","mxuitc","tthpkeo","ilhfm","mganq","akfti","savwla","jknboxy","gizapl","kkogrl","bxflyea","djeqc","trypds","ifowgv","wojnr","zqtpjh","hirqg","bfssfo","wklsjey","flvmqe","lccbypw","vatqhl","exoqnda","timli","dfqsw","vpqofqw","wkqmuw","jjrak","ehqkwsc","aszlpxn","pcljgad","oulhg","miuirt","fnpbpb","slgcj","sobzp","qjjaaz","xyzqeyp","hxcdwyz","zoxfyc","dpjezj","nhlbk","wjgbvxc","vskzyvm","yjknun","magigau","qdyztsp","tzauro","cyafd","tueqrk","vbsndz","oenku","onyxixo","cznrfu","vylwwl","cjquqf","dtvjbs","hrbax","vtfkhsv","kgunkh","gzoralk","rrnyslz","ynqxm","cpgky","xhasqk","mobfn","qzumziz","gttim","cfvghnl","bqlna","saaaoa","bdejifh","uwddhyf","ucqde","yahxi","ghjytm","pfdtj","ncqyqz","bwplqpm","jmdprp","wjzuh","oyvsn","uxlqcco","rgxzul","mzhgvih","iauvz","zpygy","mptoxu","veektwe","ulaietf","bqcymhk","hibij","fzcoy","ksrdhev","auvxxqg","bkqvrj","egkcxj","vdczklu","wopnw","wtfxx","zdryst","yfxyi","hdezi","cwsoiof","gwfuqg","wikkxzu","vakgw","jtoqr","qzrzgo","ovqtjk","fvouhbd","iunwj","aafavex","wwaisl","idcyou","pmbbjxw","icjufh","rjzog","exhvn","dypdbhr","crvpii","uylzlrp","sutckm","sxakybe","kxhlcve","xnnbz","xrvwgj","tfzqzz","mzknfo","anlfzcr","lwsdak","eqjgkk","njdqzuw","bvbrtx","jozfbs","zenxg","rkpaoft","aeztwv","zdftrrx","uurpcsk","qdxkz","ijjuxiv","excyqo","qqvbfz","aywtfnl","zpmfprc","rydfsn","nvfohp","mvbjpx","jpbkjef","ogwhp","ubaxvg","ofrqfy","zyhvyo","wlakxaa","tnzyk","saapyr","tcmpeb","etnyaq","lrgsq","mzpbs","fkczm","xxdgd","lkibi","gthxdj","dgzld","tnunjn","hzzepd","qhmoci","dskxgx","jfyyrzg","hanzy","pzier","thxkmx","fktcrf","ymdjvmf","hgzhek","qcelftn","yoget","hsadqp","ydiip","lkhztjr","pjkfbi","wskxv","qezzdtk","zereg","lcqvjym","epdlycj","lqfnau","njehxn","srafi","dhfwu","wztjr","ucwgnqv","wigdg","jkzcglz","oxxjx","yqvlodf","mmaltkd","fqahe","nfdef","urxct","hzhardk","ugvufrl","qoraj","itsymq","dxvbn","hvgmwb","vyoab","wqexj","rzimt","aejilm","fbetztv","gzktuf","yxhursl","uxluoui","vlhpj","cazppiu","skibpc","iaawl","bgpqqjw","haworva","dkdzrd","oertq","prphs","pwoikd","jzxtju","lukslx","mwzgsa","zbmymir","aarvrk","vcnarwb","yvbae","mblgdx","wpknz","ftdowg","ogayhz","qmemfr","ldqbre","oexhbh","pndmji","lmmhxnb","ecmutw","zsblbn","aimqqnz","ubsft","xzagmrb","lswjdx","glevzy","kmkzoec","kimrwg","akote","uovrxi","kfocof","sikiqtk","iyjyf","pkpsqu","otsxxoe","eoxyld","snljhud","ryuqnn","osadi","teqsj","ulvrij","kfjcz","wvfqwon","zkisf","zanaxlm","zzgegc","dvcpuj","qdgcjg","ziwqwr","enxcv","cecwvep","tqoctkw","zwoau","opkglae","olpvlts","zdtrcl","klrvh","obrqs","iwykadf","vvugv","sxskcjo","vhyeg","ydbaeb","tzgplyf","bwhyp","uwombi","svkodw","otszu","bkyqfup","rojnt","bauroa","bcribk","ctihaog","xktdiel","hkvctki","wheih","ylhxy","wgosp","bvgtk","xpclcti","uktyodd","gfblo","toaur","cxdvo","qezdwdb","mdvdk","zyhbs","akbydkw","wejgqnr","qifti","kxalog","nklzot","fgoas","apeymfw","mdjgo","xifpo","hfouhi","mdyyzf","xacds","zuijqyd","hdhsop","ivgfg","uarodof","lyqlzmc","vcyqwnj","uiekded","uosqq","quajnw","adkri","lxsbi","porjvx","awnkf","sotppb","sfhorj","uuocxz","vstcick","gqvzobl","rkccef","rlihmff","lazuav","iyahmv","jmuplkb","oforwx","ogeheqd","qpayb","txetvjv","uxsgsrj","procbt","ehlkp","vdtyz","eqjyvll","tkwrwud","qivrv","abkkllr","khpzqpp","cvlhohv","nvzbx","svvtji","wmyveiu","jrogfr","zpphtie","faoamt","ksektw","ujlilq","ufuax","mqjla","fqrnf","xcdaet","kfqknho","ofvdjn","kxopf","yysdl","dgronv","goknbep","lyhuswu","cqmvhx","hoitpoi","dgzqll","hpyea","xfzohrg","ziyod","jxkki","vbyoxz","ouylxxr","mggezan","shxvven","yrqnj","tzdyik","syeaa","fthdjm","zjzvdse","jxzdjdx","ipxpb","ollgnbu","jcdjyxj","bqltawp","lhxyv","dvggabj","ahcuqje","lnrtyaz","kubtfl","rjetqbx","fogbvq","tcwhba","ksxusyg","qlemv","dsjnth","zdmmncv","sdrzpfk","yyocl","vtqst","bobtwdu","ivifxf","uaxwlo","piqiigo","pifql","tdhuue","lrmdb","peetwl","lvwpwji","dcibnrm","ppamuxo","pknto","cbiova","wdhekr","kgipdgd","jlpvi","zoptbb","yxeamj","pjnac","tpdprx","bltdktt","wtisu","cezsmz","bbbqxk","hnyweo","jsuuu","bykgghi","spulymw","bynqe","accaq","lghcqe","nqygqvx","lfvkqbw","duzud","agmnlw","gqhqc","xkgie","fumakny","momon","scubukr","xrtmoe","ywnbn","wdkbdzv","wyflbp","vyaeb","wwzzper","veghzzz","fdkrof","bkjtao","tbvpcis","ftzghcq","yjsfg","ngdkr","pllzc","rgviwsm","mydqr","ilcjq","kmoryr","ocnwqw","zxggamr","kjlasr","idjbkt","bjvple","oauzpzw","gsxjp","sehbaf","uubptgp","ebhaa","ximeurd","kqewx","mmcaiba","lzpqva","viexed","zbcocmi","nxnuzv","vyawhnk","rozmsws","oqbubyy","lbvegpt","xfxct","jifzdqm","bmnjwmc","ptxcqc","ovzsxog","ylomlt","quoic","tlyjmyb","fgxpcf","wyhyzyb","zngau","zgsef","phsinbl","kgybiqo","tvpsi","cuxnlt","hqrrs","spkjg","kstnc","grcrons","lmbjo","mypsfq","scwir","ypngb","rwqksn","ehjufq","yulvm","vyqrmg","luyto","ueiqm","tcgcqrg","yknwn","szrbbtv","wupfh","vwrmiq","msleyih","iqtae","ezykx","ilewp","hcttjul","esiianh","wkuuv","jszkrx","gumys","lketi","zvpsb","xsvlhst","myywl","svexdk","biwsh","kpbjcdf","cyiwl","ilhfm","rvqbly","ukowa","gkmul","krtcmi","vwszj","nxwipbr","fsycct","jeglcq","donvsld","bdckkdr","iemljm","gfpgc","qilgqhx","ounvam","qyomyt","zklqshf","bpauei","kenzs","ytgaq","nnepek","tniqq","swlbj","ibdkeo","oxoed","scvcrs","jbitcfz","fjnrwjl","jogkl","pmeyrjc","kahnos","wozbzk","ytdav","pcley","kjxsvub","jfyxt","xkttisb","rvdhbpc","vvbwnmi","cecnlb","jjqemu","iasnf","usrtyx","vtastv","gcbwnft","qsiqvo","rfbua","utaxsxl","msrkymm","hjuppov","jmhmcsc","pdiujj","eafuzlc","srjvh","kzrubm","fkgzdj","kjptq","zrcid","xiuqod","nvfjea","ioeod","wncxt","avbhjud","qkxrl","rbmhfcq","shyvqbu","ffcmv","omfeko","ucibm","lexpw","rjuqey","qohfd","fjgzi","mlozc","rstgl","ntkraqo","paykcw","iaajb","adpem","gkgjbnj","yxbuvg","fqkxt","jmyqte","uzeqyj","rumyxor","gkfzleq","dwngr","thtqdtr","yptnz","xoadll","psvhyce","geoso","lijtbu","amkbuby","gfpyw","plkso","owdmtvh","fkxad","keqdrz","irxjure","gfwepm","wyxiom","pyedlj","mfszmv","tkjiofn","epjdigv","jjnuh","mtxks","nvfts","xtqhc","xttlu","sasra","qfumac","rwfavex","rcwstl","cfzmi","htvxrs","nokfsvv","tbvtckp","wsikt","tyvwtw","hyvzd","edflcy","wduqbbl","xacrrb","sfbzq","adhhyy","tltmppb","imjooie","joizol","rbzhgs","rcldg","ikspo","sxouwi","llemmdb","nkkfie","uadfas","rigylga","mbnhs","vwtsnh","uiskft","ppvhyr","znaenz","lbjldsk","sizcja","dzvlem","iedleqf","zhxzaqt","zyeen","ijdohjj","dvycit","nfqyxoc","xgspmx","gticsq","tvodn","zpvtu","yvevn","bugvglx","pprlwl","wikandw","fmkqpzp","sjfnjlf","yswptd","aeuqf","ihynsy","fnlrtb","haewxo","fvnzrx","mudxoc","vtdpd","zuldtvj","kerpq","xeesgr","enhkpmo","bhhlngf","vcqrcr","drflmq","dufvzsz","fuouj","bqcyqr","tsiyu","lrpnmx","hfqhwz","irfjh","fikhwz","qxptzm","jzppff","asutke","byouz","amqbvx","jgsfh","obdvlb","sfcdx","ofkxo","asamcnd","caxpnb","qjaqpy","zbtsmeu","atzzwkl","ebkpov","gxuyje","ybgbdd","jqaca","wnrqyt","omxxneb","xerpzsl","iadesn","mtbdwj","qftiu","fpeuu","pipsu","koxnbn","ztult","uguldn","aceqlji","uasdjf","tcydz","gswhdlg","rieim","ojplv","tjmavcp","tfbcvlh","uutoacm","ihsixk","qwvagbe","nxizc","zvwfvk","cdsyeb","hambpgs","hpsndyh","gwjoyw","ocqpmcm","xrbmn","grmefy","wwoxg","tyvgc","voeqrnu","rwnsj","cnmnz","dxltx","xnybz","jslwhka","dremxm","gfcba","fijeyqo","kxzpxyg","idjbzud","rfndjd","gqyslh","wpoznf","cbzma","dnvfyh","spguxoa","bhjhe","pehce","vwanott","giwquq","vhvwh","krukn","xojkq","mpdfbk","evlzdsw","mlbytl","dzeeupj","pfyyieu","khbxqla","pjfdf","ouvrzs","liyksgg","aimlb","jujhbu","qtxebe","nermn","itsnf","whpetav","pnjfufk","xeutgz","sbzev","vimqnd","dmagho","qfwlrsd","dnchdg","ykmrpua","fwlim","mxxhdrc","uewuwtk","cubiq","lrrot","ntfzl","epluzj","lqxnwo","cehhmlm","ntewnl","mqlxmr","yifbwx","srvzoge","ocorz","nahzh","eyxyrv","ygtxiq","lznyt","kntje","qztqnwk","zcuogu","jvvqgir","cgknqi","jzdcl","kbcnli","ofavaz","govvnq","chmuflw","vxkxu","lgzbgu","oaeleyg","wbjjdiq","rxzei","orhgon","swmrkye","lfecfum","zrwygt","dnsly","wayaxe","idvhdd","nzlrr","qinomxp","zqexfqg","cgirjzp","cxyrqt","jledfgr","xstkbu","lsazo","vqlam","bwdacez","mpyxys","mjljmde","hztog","tjubtlz","vhhhn","ssercal","xthbxt","icyiu","iljzz","zhnjfm","cktcwjh","qetdt","gdeenr","lcktgy","wzwoug","mefjve","fryrl","fefwp","dzvow","ytomt","wglib","komqcu","wztnrs","gestvx","hquwilc","mxfzqf","svhwm","viymyf","uolmu","uirzdao","iyprm","uxjnyzd","rcwczh","qofsqkz","oefie","gmtgrn","krrfs","bfhsdnq","cowzu","fgrjjz","xtpdn","wiepso","slgjrjd","inlimj","nscgl","vvnby","kxckw","gllbjjp","juvui","kbzjd","odhqpx","pnpkvf","fuleic","inawlx","essdsdj","fvlud","ttvjwz","cnkmtdy","xlchd","isqhk","vmilcks","xoifyy","bkygwh","mgzdpre","waemqvd","ricio","wycuo","bqzkd","pjazcp","kqviffk","ojfvq","unlbnfb","detmfih","nytprpm","fevnwin","iydfpqc","pkhlbi","aetnje","pzojli","basba","xutuv","akncyfb","nsiwt","shovlwd","qyayx","mzjcre","xadyr","dxpxj","mlcpp","zzyaht","vwqhyeq","dwmla","oizmbr","egwzibj","rfbmu","fuzhg","ynlbutf","yycgtro","humfhb","lrkkga","xglbsoe","mvrdb","fvxjbw","lomacg","fmfmal","qykti","oujsp","nohogca","dbyvxbi","eawic","qfzwp","xrzbec","rrqyw","mtbhs","hbrnv","fnmeikj","mwogm","ovxyvn","cvkqxcr","xfnobdy","pkity","rbgtuwh","odjnv","zksyrl","rzuceuk","qukxs","ipznvtc","bsvzooz","nzbpb","xpiiir","chkqepj","wzwzzcw","rhptep","yjccu","avijaiv","kxpms","ovwqsgo","jjqvi","wyrxpu","kybsyhw","kvyaj","dnusp","irgrjyj","wpeico","psgnk","joevw","pfyqwr","sxlmcs","ibblhvx","aecsjes","tuqnfd","avemo","fvijtdb","zcehesf","yowvgv","fnrgd","jpvkykx","ekyho","abtxc","hptqmiy","duwef","bdsac","mgamp","wtsto","efxhwad","yhjwfe","adnhhh","ouykgrh","sbtpmr","fzkps","mdilvvn","ztvysu","rafkn","ledgijl","ewlnpsr","cedlekw","gngcu","phbqtb","znfjwqk","wrqkv","tayvdd","cceqg","dabgyh","wgutqn","klseoo","kaktas","einjkvf","gzmbvur","plcskol","vhpzaqz","gcezm","giavzjt","prrai","szrtye","lbegl","jkkunm","ociydiw","kstxl","bqxhkzh","jzzjv","vbjzopr","jvdkro","padxe","pmezf","eqwlb","nupajjp","bkunbit","xjqxtr","wzuqmc","dqozgi","diqfj","eqlfngp","gvnggid","znylx","jajie","qmsamw","mttvg","gzamj","cscnb","bvtreg","qhbiq","eklkjp","fbcyl","rdjsfqf","qevuv","jwislw","unjvd","fsbvb","wqcrho","orrylro","zoxokla","dgoja","rgwja","vqpzfh","llhtc","afoic","arscma","qfwfli","ivcncxd","ximts","kwfebh","wffmri","ljace","eonkn","ueapcli","qmocdvr","mdviccj","vwvyl","savupw","fanliyh","ykwvsh","yzqez","vdxepxm","soocy","jqczsb","ckufr","gyusijy","sbdvh","hgbqt","zrcka","mhfhy","shksov","pfliju","xlesen","rgqiz","mnajzkt","iozcs","hqikmbq","ervfyim","ezddw","kgklyaw","sfmqe","lnaexsi","llvvt","bhiwu","riigy","gtdxlh","vpkoeau","apapx","ebpwll","pkhqe","erulwb","ljxkn","zhcgls","ejvxh","fwlsjmq","yrrykh","stcxaw","tgpbny","grvkdk","svuzxpf","jwsmwcm","kayffuh","xnaisep","qigyx","dxnje","nplwles","qqomb","xrnrvr","qmqxr","datvf","vllggut","cadczx","nknpbhk","izowycz","pekxqfk","unbrsm","mcjown","kaqiw","obrurt","dmwqli","atjrc","oqmlell","wymlr","xjpkztx","wjyhkna","otqju","hblgv","lxrbs","gyfwu","vdpmt","kjmdibo","ozapzmw","jwcgtq","dfymo","qagvqil","hittrny","uinvmlm","tehfpsl","vpqnzqy","sroki","inxetz","isnmony","nzmvf","dzufni","nexqh","fkjnvma","gwvst","idhwax","neeuvln","iecja","zwzdp","vfppg","obbei","dfgopn","acijhp","ixwtkp","fpyny","rzozlxq","djuov","hhfjcl","kcnfa","grguw","dduiej","rewvs","imlwk","fosbbtq","xjclkjn","wwpqgb","jovsfes","mhiaeuj","fxjgk","enngxv","skiaud","whfkr","igchqb","kftala","dwjxl","xepvk","qidfjb","titaly","jplijvv","nuzcon","slleg","tyycth","dtvrvpd","yubfqoi","pkwsff","zbbko","nrggf","hqgnna","yfumb","qubvic","qjpwo","vmepg","btawj","zveot","xaivzxu","tknsmv","fgbvza","fnsnqs","qbismc","arhyycq","evvxs","xpkees","nuumqyd","yzqdh","oeeuxh","vmjcm","lkvgv","mpxrugr","tkxnx","cpafxvh","wrswmb","eadznj","bdvgwz","ahiegu","shedlup","sejcyww","zbusii","lzdzak","oymze","vhbrz","digdz","xphzgg","levzi","tgkvqp","kmxcnm","bnwlngx","iejarx","dizrscz","vsyqnv","zkuoye","beojpk","hfhvzg","gisjftm","dvweqa","keauzic","lkjby","ngguexc","pohngye","afjtde","xhddc","hhttmgi","caczjl","wgkfbv","ulvax","uemxgxs","uqfzxu","keaaw","pdxhn","waoly","ukvfwy","pentckg","bgypmd","ozywxef","kxbyg","ituij","yssywlv","iybzdz","knpyeub","sbkrdlh","hsqvas","wrjiuyo","pgogqmv","ofsoix","dxldl","ezhgfxg","igpkh","bobmm","gddpayx","ejihwu","evxddr","wdlcpqn","zlucrvj","lciroeu","tozwakg","ymrlcji","cpupkp","oqjaa","ikerp","eghad","tntbl","giqxr","szavqhz","acqawb","hdfytnu","qoksmwl","snnplu","drvhr","uyjef","kjlpxcr","wivxg","jemkix","mlhcmd","vlivttu","georzc","vagamm","gndipgf","cmvsbmv","pbfyvz","pgwye","qyxpvs","grjadvo","vgfev","kpfloyz","lchpqln","eejfkcs","vlkrhp","ppfukr","pgrjbg","wogtj","cgivop","jnpqoj","ldlpbrr","vlgal","kbjar","dngqm","ikgadp","jipvwuq","xqvjkl","ojtecxz","updfcm","xwbhr","qhupf","yuiat","jhpfebe","vnrrunw","eunefe","kzcbqd","fvxufv","koynws","dgyfwb","nyvekrk","rjuotpr","ymdwzj","dnkmrlt","abykta","ubmbjdy","pvarsmz","ttnvs","jqhejm","zvrek","edhxibz","qexny","oagswer","twtur","fmcbl","qmdma","zthlqwv","bhwps","czqgr","gqbrrxx","nkvgzrs","cazmrjq","nieyb","bgsgq","ukfakiz","yztyra","tyfrigv","wlfhd","rbyunj","usvypgo","hhkej","jivtlg","ifgzqu","ofjrlw","rlqyxnm","smljy","mbgwv","fwlehwb","qlogyx","faxwc","axaeo","hkgsppo","dencdr","ddhbps","jbxxoc","pjxyk","ctvqy","qvvpzyu","yewduf","mugmbte","lzfqvuc","vhxpg","jnmqj","ennlwu","qmjhiqg","adierw","goezh","vjnoz","rqagh","emtspp","nmmhe","ssomw","ofkwv","ludzh","otpfssv","snwjzz","ahimcsq","tgoxkeg","shnsfau","cmcdlym","ybnft","kcoyn","bonazcf","gufvm","tpmlzom","eyzmod","dokojaj","xadbjwk","ffvle","ntteh","jevrazt","efkhc","bbwntl","srihk","kmjadz","qkxsvbq","ddljp","uwwuvth","bipgo","ihsmv","xmmmcsj","odmqr","fttvlys","shehiuy","icgwi","nsvmg","zqjjkyk","umrie","spbqz","xmidgzv","yadhc","mspibhn","xtgxom","rasfnft","blerfgx","zfpfq","xkfclje","tbzvw","vgbvg","ayngxcp","ndyle","vqbgsce","fpshlx","vqufvgv","dkyccvy","yyuyjf","rfxmqdn","sxugzm","gjhbkv","xhdjvx","ymykgxb","prknrk","eabbpqr","qxojf","lzwhuby","cpozcue","ishbwlf","mduhyjx","rrhhav","ufbafzp","mfpwuww","pobnaaj","lrsxxj","cohjf","jkbxz","sarme","grklhj","tqvkqy","ytikna","asntarp","gslbu","exorbu","cjkwzu","psdma","zzpdol","dvgloav","yxbfakk","emmcvx","jlguic","jjxkfmt","iuendwj","rathmt","qyweiba","xafoy","dqsnc","hvkowm","eabcao","phydpb","rndnfwg","qjahwwx","ytpal","htmau","dopybqz","nvjif","vwwqi","qermpq","iizvetj","xqfos","rtcuhbe","igjrfme","ubxbb","qppcb","nohfxao","nfyncug","ddzhw","froajrf","sjjiss","kqitq","unzlbaj","sbdaepv","tvmhcga","kqhgtom","vamfzf","gyofhng","mabbme","zdchndq","zybctyd","psqbrzl","hyxfsrj","xtgkdh","ptwqat","uucrov","igljkfu","pktoiui","nhyil","cshte","pfsqa","nsfsmze","twcuf","jfqwtd","vinzb","afruk","txldlnj","jsttu","pkbczjm","txpfq","xbhwtcg","cmcho","jtuixpl","xfefj","oapaczq","xcpvsw","qbudm","xdvtr","hwkmj","zagtjpd","ohnawr","flxbat","epicea","xmjnmbw","ywvfcz","rvyel","nsuwwuz","kknoqq","mhsfiz","hnromvi","dedzukf","uldavy","pdcec","qojqpmf","sivfru","xjayrn","xwjuah","vkqmb","wuvkxpc","nrhsb","hashdly","oeudry","foqpt","sdexar","nuyli","smxpkk","mjheihb","zmxlu","ouiisf","gmhjbb","zozpja","diimrrm","uwonbw","pegxoxf","obdtpcn","fdadto","aekkg","fjjxmeu","dkqpptm","wbfuzr","lfteh","rbtfbzo","eglch","qxrru","oofwkgz","rgigqr","gnjpoep","uexcxs","mwfgk","embebip","suans","oagqbqx","plyzcsq","huggwzw","ccsxy","waixkjw","doqwr","uqxkvkc","yurkj","slgbj","mbqzm","yssszr","htoph","gupqhgj","kkrsdv","uiuxfp","qxacm","uwmqc","jbnzh","sqyalww","kcjsmx","lonsz","pzsmu","cjqvjw","qiiulzm","wfoqt","kdjnfe","dsnpjn","xnzmimc","ulvdd","fvxpmm","rzklco","whyolla","ppmex","bgaoi","vskeguj","kjwbh","wzskso","lnpkvie","lcxsnc","ddwpwc","hezxemz","tcgkj","yawyd","oymed","ukqrx","zfwmo","ifswz","mzjuo","cafpb","kubdbe","owkux","rhrvb","usaev","pkffvsn","uindrki","xeemo","qumuu","pldri","ghusk","xkzsrym","mndqb","fpvokz","kfmeg","lrhmj","refbzvk","qlbrmp","ddjuaj","foyet","qtdujqj","uwvhxsj","xtmtkiz","xpwvh","fcgll","dlnwmj","rmfnoz","pomnxn","vhjcyi","totup","udgpv","axpaddc","qtzmga","hoszek","smsmmvg","qoyvj","vxqigxy","pvwynx","puxjpjv","odcaxeo","daeuw","cdugp","sgwgjdx","buhfyf","yiwykai","ojtfyal","tjaob","oimmn","bdtnidq","zhysw","bojjkf","wkgqrd","njecfik","cnndzrq","dsiaa","kumtk","towbx","bzoirpz","vtnxby","plhdj","rqpai","ztaousd","vspwkxu","mikncyf","pafxpnc","bggcmvj","tahqf","izchgc","xaspz","zwfwl","cwgcuci","wzuzq","rgrsyzu","mgytix","kqqakjw","eekgzcm","txbcw","fcoxkag","kqxac","licntr","vmweor","bslmfto","jzalnup","tuiep","dacwc","zntmpb","ikexnhq","mlioa","klwpv","ddhbtg","jurwdf","jutynuo","dlcicqo","cnvqsq","qqsiszn","vqabt","huaoigf","bmlpczh","dsnuy","qrrqv","edoxkud","uqxdk","gyphg","rvyzzz","epjhqj","dejkvae","zczwgm","ulisrt","ihuayib"};
    v = vector<string>{"time", "me", "bell"};
    v = vector<string>{"t"};
    v = vector<string>{"feipyxx", "e"};
    s.minimumLengthEncoding(v);
    return 0;
}

/*
A valid encoding of an array of words is any reference string s and array of indices indices such that:

    words.length == indices.length
    The reference string s ends with the '#' character.
    For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].

Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.
*/

namespace beautiful_sample {
class TrieNode {
public:
  unordered_map<char, TrieNode *> next;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
      TrieNode *root = new TrieNode;
      vector<pair<TrieNode *, int>> leaves;
      for (auto & w : unordered_set<string> (words.begin(), words.end())) {
        TrieNode *cur = root;
        for (int i = w.length() - 1; i >= 0; --i) {
          if (cur->next.count(w[i]) == 0)
            cur->next[w[i]] = new TrieNode;
          cur = cur->next[w[i]];
        }
        leaves.push_back(make_pair(cur, w.length() + 1));
      }
      int res = 0;
      for (auto leaf: leaves) if ((leaf.first->next).size() == 0)
        res += leaf.second;
      return res;
    }
};
}
