#include<bits/stdc++.h>
using namespace std;
void LU(double mat[][50],int n,char var_name)
{
    double A[20][20]= {0},L[20][20]= {0}, U[20][20];
    double B[20]= {0}, X[20]= {0},Y[20]= {0};
    int i,j,k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
           A[i][j]=mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {

        B[i]=mat[i][n];
    }

    printf("[A]: \n");

    for(i = 0 ; i<n ; i++)
    {
        for(j=0; j<n ;j++)
        printf("%9.3lf ",A[i][j]);
        printf("\n");
    }
    printf("[B]: \n");
    for(i = 0 ; i<n ; i++)
    {

        printf("%9.3lf ",B[i]);
        printf("\n");
    }

    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i<=j)
            {
                U[i][j]=A[i][j];
                for(k=0; k<=i-1; k++)
                    U[i][j]-=L[i][k]*U[k][j];
                if(i==j)
                    L[i][j]=1;
                else
                    L[i][j]=0;
            }
            else
            {
                L[i][j]=A[i][j];
                for(k=0; k<=j-1; k++)
                    L[i][j]-=L[i][k]*U[k][j];
                L[i][j]/=U[j][j];
                U[i][j]=0;
            }
        }
    }
    printf("[L]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3lf",L[i][j]);
        printf("\n");
    }
    printf("\n\n[U]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3lf",U[i][j]);
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        Y[i]=B[i];
        for(j=0; j<i; j++)
        {
            Y[i]-=L[i][j]*Y[j];
        }
    }
    printf("\n\n[Z]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3lf",Y[i]);
        printf("\n");
    }



    for(i=n-1; i>=0; i--)
    {
        X[i]= Y[i];
        for(j=i+1; j<n; j++)
        {
            X[i]-=U[i][j]*X[j];
        }
        X[i]/=U[i][i];
    }


    printf("\nSolution for the system:\n");
    ofstream of("output.txt");
    of<<"\nSolution for the system:\n";
    for (int i=0; i<n; i++)
        if(var_name>=65 && var_name<=90)
        {
            string unknown="";
            unknown+=('A'+i);
            cout<<unknown<<" = "<<X[i]<<endl;
            of<<unknown<<" = "<<X[i]<<endl;
        }
    else
    {
        string unknown="";
        unknown+=var_name;
        stringstream ss;
        ss << (i+1);
        unknown+=ss.str();
        cout<<unknown<<" = "<<X[i]<<endl;
        of<<unknown<<" = "<<X[i]<<endl;
    }


}
void print(double mat[][50],int N)
{
    printf("Given:\n");
    for (int i=0; i<N; i++, printf("\n"))
        for (int j=0; j<=N; j++)
            printf("%9.3lf ", mat[i][j]);

    printf("\n");
}
int main()
{

  string line;
  double val;
  char var_name;
  int var_pos,sign=1,mx=-1;
  double mat[50][50];
  memset(mat,0,sizeof mat);
  ifstream myfile ("input.txt");
  vector<double> rhs;
  if (myfile.is_open())
  {
      int i=0;

    while ( getline (myfile,line) )
    {
        bool equal_sign=false;
        stringstream ss(line);
        sign=1;
        while(ss>>line)
        {
            if(line=="=")
                equal_sign=true;
            else if(line.size()==1 && line=="+")
                sign=1;
            else if(line.size()==1 && line=="-")
                sign=-1;
            else if((line[0]>=48 && line[0]<=57) || line[0]=='.' || line[0]=='-')
            {
                stringstream sss(line);
                sss>>val;
                if(equal_sign==true)
                {
                    rhs.push_back(val);
                    continue;
                }
                sss>>var_name;
                if(var_name>=65 && var_name<=90)
                {
                    mat[i][var_name-65]=val*sign;
                    mx=max(mx,var_name-64);
                }
                else
                {
                    sss>>var_pos;
                    mat[i][var_pos-1]=val*sign;
                    mx=max(mx,var_pos);
                }
            }
            else
            {
                stringstream sss(line);
                sss>>var_name;
                if(var_name>=65 && var_name<=90)
                {
                    mat[i][var_name-65]=1*sign;
                    mx=max(mx,var_name-64);
                }
                else
                {
                    sss>>var_pos;
                    mat[i][var_pos-1]=1*sign;
                    mx=max(mx,var_pos);
                }
            }

        }
        i++;
    }
    for(int i=0;i<rhs.size();i++)
        mat[i][mx]=rhs[i];
    print(mat,mx);
    myfile.close();
  }
  LU(mat,mx,var_name);
}



