#define MAXSTRIDE 10240
class Stride {
public:
    unsigned short stride;
    unsigned short priority;
    unsigned short times = 0;
    Stride(unsigned short s, unsigned short p) : stride(s), priority(p) {};
    void run() { cout << "run" ; stride += (unsigned short)(MAXSTRIDE / priority); times++;}
};

// void schedule(Stride* s1, Stride* s2) {
//     if ((short) (s1->stride - s2->stride) <= 0) {
//         cout << "process 1 and currently its stride is " << s1->stride << endl;s1->run();
//     } else {
//         cout << "process 2 and currently its stride is " << s2->stride << endl;s2->run();
//     }
// }

// void test() {
//     Stride* s1 = new Stride(18, 2);
//     Stride* s2 = new Stride(126, 4);
//     for (int i = 0; i < 300 ; i++) {
//         schedule(s1, s2);
//     }
//     cout << "process 1 has been scheduled " << s1->times << " times" << endl;
//     cout << "process 2 has been scheduled " << s2->times << " times" << endl;
// }
