class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1) return (double)1;
        if(n<0) {
            long long int n1 = (long long int)-1*n;
            double tmp = myPow(x,n1/2);
            if(n1%2) return 1/(tmp*tmp*x);
            else return 1/(tmp*tmp);
        }
        if(n==1) return x;

        double tmp = myPow(x,n/2);
        if(n%2) return tmp*tmp*x;
        else return tmp*tmp;

    }
};