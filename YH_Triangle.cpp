#include <stdio.h>
typedef long long int LL;
int n;
LL max(int a, int b)
{
    LL max = a;
    if (b > a) max = b;
    return max;
}
LL C(int a, int b)//a>=b,�������
{
    if (b == 0 || a == b)return 1;
    LL res = 1;
    for (int i = a, j = 1; j <= b; i--, j++)
    {
        res = (res * i) / j;//������ϸ�����Ƚ���res*i������㣬��֤�������������
        if (res > n)
            return res;
    }
    return res;
}
int check(int k)//checkʹ��б���ֲ���
{
    /*�������������ǣ�ȷ���˴ӵ�kб�п�ʼ��飬�ҸôӸ�б�е���һ�п�ʼѰ��n��
    ���壺r��Ҫ�ҵ���n���кţ�k��б�е���ţ�Ҳ��n���кţ���L�Ǹ�б�еĵ�һ����������*/
    LL l, r, mid;
    l = 2 * k;//�����16б�еĵ�һ������������32��L����32��L���Ǽ������
    r = max(n, l);
    /*�ڶ�б�������������У��ٸ����ӣ���Ҫ����10��Ȼ���10�еĵڶ�����Ҳ���Ǵ��ڵڶ�б���ϣ�
    ��10,�ҿ϶����ҵ���������Ҫ���¼���ˣ������Ⲣ���ǵ�һ�γ���10,10�ڵ�5�оͳ��ֹ��ˣ�
    ��ȷ������ 10��һ�γ��ֵ�����һ����10 
    �ƹ��Ժ���Ҫ��n�����鵽��n�о��С���L����С�������������L�϶���nС��
    �ǿ���ֱ��дr=n�𣿲����ԣ���Ϊn��������Ķ�����
    n����Ϊ��������Ϊ0���Ҿ���Ӧ�øĳɣ�
    if��n<1)
       cout<<"������"<<endl;
    else
       r=n;
    ����ԭע���C(n,2)=n�Ǵ���ʽ�ӣ�Ӧ����C��n��1��=n���ڶ�б����C��n��1��������б����C��n��2��
    ��ԭ�ģ�:�߽�ȡn����Ϊһ������C(n,2)=n��ʱ�ڵڶ�б�У��ڶ�б���д�1��ʼ����������*/
    
    while (r > l) //�ܽ���ѭ��˵��r��LҲ��������ȡ����r=n��
    {
        int mid = (l+ r) / 2; //��һ�ε�ʱ��l����С������r=n�����������mid��ֵ��ȡ�԰�
        if (C(mid, k) >= n)/*��i�е�j�е�ֵ��C(i��j)������mid�е�k�е�����n��
                            ˵��n�����ڵ�mid�����棬������������r=mid*/
            r = mid;
        else l = mid + 1;/*��֮������һ�е�����nС��������L�����Ϊmid = (L+ r) / 2��L����ˣ�
                         ��mid���mid����һ�У�C(mid, k)Ҳ����ˣ��������>= n��˵��
                         n�����ڵ�mid�У�r������ŵ���*/
    }/*�����һ�ξͳɹ�r=mid����Ϊmid�Ǵ���L�ģ��������ѭ�����൱��midһֱȡ�԰룬
     r�ֵ���mid��rԽ��Խ�ӽ��Ǹ�Ψһȷ����������
     ȡ�԰�ĺô��ǣ�������Ҫ��999999����L��ʼ��32���԰��Ժ�mid���500015��
     ���n���ڵ�500015�У�L�ͱ��500016��
     ����Է���L��32Ծ����500016���԰�ȡ�Ǻܿ�ģ�����һ��һ�мӡ�����*/

    //ѭ���������õ���Ψһȷ����rֵ

    if (C(r, k) != n)/*����C(r��k)�ǲ���Ҫ�ҵ�nֵ��������ǣ�
                      ��main��������֪�����б�еļ������ˣ�ȥ�����һ��б��*/
    {
        return 0;
    }
    else {
        printf("%lld", (r + 1) * r / 2 + k + 1);
        /*�ҵ��ˣ�(r + 1) * r / 2 + k + 1�Ǽ���Ҫ�ҵ����ǵڼ���*/
        return 1;n
    }
}
int main()
{
    scanf("%d", &n);
    //iȡ16����ΪC(34,17)�Ѿ�������Ŀ��n�ķ�Χ
    for (int i = 16; ; i--) {
        if (check(i))
            break;
    }
    return 0;
}