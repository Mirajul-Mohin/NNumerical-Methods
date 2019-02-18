#include<bits/stdc++.h>

using namespace std;


void Gauss_Seidel(double mat[][50],int n,char var_name)
{
    double a[10][10],b[10],x[10],y[10];
    int m =0,i=0,j=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            a[i][j]=mat[i][j];

        }
    }
    for(i=0; i<n; i++)
    {
        b[i]=mat[i][n];
    }
    cout<<"Enter initial guess: ";
    for(i=0; i<n; i++)
    {
        cin>>x[i];
    }
    cout<<"\nEnter the no. of iteration: ";
    cin>>m;
    int tmp=1;
    while (m>0)
    {

        printf("\nIteration %d:\n",tmp);
        for(i=0; i<n; i++)
        {
            y[i]=(b[i]/a[i][i]);
            for(j=0; j<n; j++)
            {
                if(j==i)
                    continue;
                y[i]=y[i]-((a[i][j]/a[i][i])*x[j]);

            }
            x[i]=y[i];

            if(var_name>=65 && var_name<=90)
            {
                string unknown="";
                unknown+=('A'+i);
                printf("\t\t");
                cout<<unknown<<" = "<<y[i]<<endl;
            }
            else
            {
                string unknown="";
                unknown+=var_name;
                stringstream ss;
                ss << (i+1);
                unknown+=ss.str();
                printf("\t\t");
                cout<<unknown<<" = "<<y[i]<<endl;
            }



        }
        cout << "\n";
        m--;
        tmp++;
    }

    printf("\nSolution for the system:\n");
    ofstream of("output.txt");
    of<<"Solution for the system:\n";
    for (int i=0; i<n; i++)
        if(var_name>=65 && var_name<=90)
        {
            string unknown="";
            unknown+=('A'+i);
            cout<<unknown<<" = "<<y[i]<<endl;
            of<<unknown<<" = "<<y[i]<<endl;
        }
        else
        {
            string unknown="";
            unknown+=var_name;
            stringstream ss;
            ss << (i+1);
            unknown+=ss.str();
            cout<<unknown<<" = "<<y[i]<<endl;
            of<<unknown<<" = "<<y[i]<<endl;
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
    ifstream myfile ("example.txt");
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
        for(int i=0; i<rhs.size(); i++)
            mat[i][mx]=rhs[i];
        print(mat,mx);
        myfile.close();
    }
    Gauss_Seidel(mat,mx,var_name);

    return 0;
}
