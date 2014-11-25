#include <iostream>
using namespace std;

void PreOrder (int pom) {
      cout << LabelT(pom, stablo) << " ";

      if (FirstChildT(pom, stablo)!=-1)
         PreOrder(FirstChildT(pom, stablo));

      if (NextSiblingT(pom, stablo)!=-1)
         PreOrder(NextSiblingT(pom, stablo));
}

void PostOrder (int pom) {
      if (FirstChildT(pom, stablo)!=-1)
         PostOrder(FirstChildT(pom, stablo));

      int pomv = pom;

      if (FirstChildT(pomv, stablo)!=-1)
        {
         pomv=FirstChildT(pomv, stablo);

         while (NextSiblingT(pomv, stablo)!=-1)
            {
               pomv=NextSiblingT(pomv, stablo);
               PostOrder(pomv);
            }
         }

      cout << LabelT(pom, stablo) << " ";
}

void InOrder (int pom) {
      if (FirstChildT(pom, stablo)!=-1)
         InOrder(FirstChildT(pom, stablo));

      cout << LabelT(pom, stablo) << " ";

      if (FirstChildT(pom, stablo)!=-1)
        {
         pom = FirstChildT(pom, stablo);

         while (NextSiblingT(pom, stablo)!=-1)
            {
               pom=NextSiblingT(pom, stablo);
               InOrder(pom);
            }
         }
}
