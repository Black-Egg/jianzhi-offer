#include<iostream>
#include<cmath>
using namespace std;
double a[5];
#define EPS 1e-6

bool isZero(double x){
    return fabs(x)<=EPS;
}
bool count0(double a[],int n){
    //用数组a里的n个数，计算24
    if(n==1){
        if(isZero(a[0]))
            return true;
        else
            return false;
    }
    double b[5];
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            int m=0;
            for(int k=0;k<n;k++)
                if(k!=i&&k!=j)
            b[m++]=a[k];
            b[m]=a[i]+a[j];
            if(count0(b,m+1))
                return true;
            b[m]=a[i]-a[j];
            if(count0(b,m+1))
                return true;
            b[m]=a[j]-a[i];
            if(count0(b,m+1))
                return true;
            b[m]=a[i]*a[j];
            if(count0(b,m+1))
                return true;
            if(!isZero(a[j])){
                b[m]=a[i]/a[j];
                if(count0(b,m+1))
                    return true;
            }
            if(!isZero(a[i])){
                b[m]=a[j]/a[i];
                if(count0(b,m+1))
                    return true;
            }
        }
    return false;
}
int main()
{
    int n=0;
    while(1)
    {
        for(int i=0;i<3;i++)
        {
            scanf("%lf",&a[i]);
            if(a[i]==0)n++;
        }
        if(n==4)
            return 0;
        if(count0(a,4))
            printf("YES");
        else
            printf("NO");
    }
}
