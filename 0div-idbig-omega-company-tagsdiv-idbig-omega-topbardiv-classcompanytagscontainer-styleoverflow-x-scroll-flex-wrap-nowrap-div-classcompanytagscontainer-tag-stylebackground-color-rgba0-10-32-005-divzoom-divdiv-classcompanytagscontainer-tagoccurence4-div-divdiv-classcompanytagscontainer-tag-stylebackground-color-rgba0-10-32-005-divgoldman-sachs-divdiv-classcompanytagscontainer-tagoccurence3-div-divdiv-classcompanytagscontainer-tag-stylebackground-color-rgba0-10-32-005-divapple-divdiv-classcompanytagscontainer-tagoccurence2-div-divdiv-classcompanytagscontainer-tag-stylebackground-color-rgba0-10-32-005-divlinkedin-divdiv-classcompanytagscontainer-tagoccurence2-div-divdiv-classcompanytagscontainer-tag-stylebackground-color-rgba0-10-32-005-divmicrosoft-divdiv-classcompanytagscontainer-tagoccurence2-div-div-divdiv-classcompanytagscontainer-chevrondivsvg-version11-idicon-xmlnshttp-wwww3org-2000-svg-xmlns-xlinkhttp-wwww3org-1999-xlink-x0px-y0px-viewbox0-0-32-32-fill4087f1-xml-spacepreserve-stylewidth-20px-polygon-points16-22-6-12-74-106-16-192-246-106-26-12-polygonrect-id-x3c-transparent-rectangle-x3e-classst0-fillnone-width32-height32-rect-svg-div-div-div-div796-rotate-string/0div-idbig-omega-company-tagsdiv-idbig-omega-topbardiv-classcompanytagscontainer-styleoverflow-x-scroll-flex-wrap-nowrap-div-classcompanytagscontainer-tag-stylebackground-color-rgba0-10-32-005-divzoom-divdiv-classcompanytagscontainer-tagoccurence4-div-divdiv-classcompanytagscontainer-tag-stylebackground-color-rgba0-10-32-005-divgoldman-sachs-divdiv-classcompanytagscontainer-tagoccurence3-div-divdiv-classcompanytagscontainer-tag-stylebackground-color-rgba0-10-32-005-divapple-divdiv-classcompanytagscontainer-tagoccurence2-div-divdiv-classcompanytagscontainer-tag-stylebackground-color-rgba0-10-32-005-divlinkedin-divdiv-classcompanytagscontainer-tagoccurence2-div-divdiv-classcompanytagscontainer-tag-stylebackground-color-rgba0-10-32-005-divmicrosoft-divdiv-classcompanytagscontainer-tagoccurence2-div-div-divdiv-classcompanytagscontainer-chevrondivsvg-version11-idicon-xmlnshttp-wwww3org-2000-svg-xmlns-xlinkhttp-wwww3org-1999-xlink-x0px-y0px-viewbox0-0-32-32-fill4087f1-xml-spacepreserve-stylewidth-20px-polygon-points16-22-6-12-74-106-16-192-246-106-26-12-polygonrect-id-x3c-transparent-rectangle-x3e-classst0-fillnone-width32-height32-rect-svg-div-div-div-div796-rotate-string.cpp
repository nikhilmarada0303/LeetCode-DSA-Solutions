class Solution {
public:
    bool rotateString(string p, string q) {
//         if(p.size()!=q.size()) return 0;
//     int ans = -1;
//     for (int k = 0; k < p.size(); k++) {
//       if (q[0] == p[k]) {
//           ans=k;
//         int i = 0;
//     int j = q.size() - ans - 1;

//     while (i <= j) {
//         if (p[i + ans] == q[i]) {
//             i++;
//         } else {
//             return 0;
//         }
//     }
//     while (i < q.size()) {
//         if (p[(i + ans) % p.size()] == q[i]) {
//             i++;
//         } else {
//             return 0;
//         }
//     }
//         if(i==q.size())
//             return 1;
//       }
//     }
//     return 0;
        if(p.size()!=q.size()) return 0;
    p=p+p;
    if(p.find(q)!=string::npos) return 1;
    return 0;
    }
};