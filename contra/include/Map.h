#ifndef MAP_H
#define MAP_H
#include <iostream>
using namespace std;

class Map
{
    public:
    string nivel[19] = {
            "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
            "0                                                                                                                                                                                                                                                         0    PPPPPP",
            "0                               w                                                          w                           2              w                                                              w                       w                            0    PPPPPPP",
            "0        w                                          d                    w                                          d                                                                                                                                     0    PPPPPPP",
            "0                                                   kkkk           M                                 d dd           kkkkk                                                                                                                               F 0    PPPPPPP",
            "0                                                                d                    w              kkkkkkk                  w                      w                                                            w                                       0    PPPPPPPP",
            "0                                                                kkkk                         d  c             dd                                                          w                          d                                                   0    PPPPPPPP",
            "0                        d                 dd                                                 kkkk             kkkkkk                                                                                 kkkk dd                                             0    PPPPPPPP",
            "0                        kkkk            d kkkkk                                                                 kkkk                      0d d  dd   0                                                     kkkkk                                         0    PPPPPPPPP",
            "0               d                        kkkkkkk              1              M                     d             kkkk                       kkkkkkkkkkk                                                                                                   0    PPPPPPPPP",
            "0               kkkk                  d  kkkkkkk        d dd               d                       kkkkk         kkkk                       kkkkkkkkkkk                         d  d                                                                   3  0    PPPPPPPPP",
            "0                                     kkkkkkkkkk        kkkkkkkk           kkkk                                  kkkk                                            d  d           kkkkkkk                                 c          dkk                    0    PPPPPPPPP",
            "0        d                        d   kkkkkkkkkk        kkkkkkkk                                             d   kkkk                                            kkkkkkk                         d kk                              kkkkk         d        0    PPPPPPPPP",
            "0        kkkk         G           kkkkkkkkkkkkkk        kkkkkkkkkk0G                          G             0kkkkkkkk0       G                     G          d 0kkkkkkk              G         dkkkk       G          d  kk   d   kkkkkk      d kkkk     0    PPPPPPPPP",
            "0        kkkk                g    kkkkkkkkkkkkkk        kkkkkkkkkk0          g       g     c                0kkkkkkkk0          g      cg    g               0kkkkkkkkkk   g          g       c kkkkkk           g     kkkkk   kkkkkkkkkkkkd   kkkkkk g g 0    PPPPPPPPP",
            "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP       PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
            "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP       PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
            "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP       PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
            "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
            };
    private:
        string cambio;

};

#endif // MAP_H
