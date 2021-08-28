#include<bits/stdc++.h>

using namespace std;

string numberToString(int num){

    stringstream iss;
    iss<<num;
    string str;
    iss>>str;
    return str;

}


void Bankers_Algorithm(){


    int resourceNum,processNum;
    vector<string>vecstr;
    vector<int>indexOfallo;

    ifstream ifile;
    ifile.open("Banker'sAlgorithmFile.txt");

    vector<int>store[100];


    ifile>>processNum;


    ifile>>resourceNum;

    vector<int>allocation[processNum+1];
    vector<int>maximum[processNum+1];
    vector<int>need[processNum+1];



    for(int i=0;i<processNum;i++){

        for(int j=0;j<resourceNum;j++){

            int temp;
            ifile>>temp;
            allocation[i].push_back(temp);
        }
    }




    for(int i=0;i<processNum;i++){

        for(int j=0;j<resourceNum;j++){

            int temp;
            ifile>>temp;
            maximum[i].push_back(temp);
        }
    }


    cout<<"creating need number"<<endl;


    for(int i=0;i<processNum;i++){

        for(int j=0;j<resourceNum;j++){

            int temp = maximum[i][j] - allocation[i][j];
            need[i].push_back(temp);
            cout<<temp<<" ";

        }
        cout<<endl;
    }


    int available[resourceNum+1];


    for(int i=0;i<resourceNum;i++){
            ifile>>available[i];
    }


    int requestProcess;
    ifile>>requestProcess;


    int request[resourceNum+1];

    for(int i=0;i<resourceNum;i++)
        ifile>>request[i];

    bool tag = true;
    bool tag1=true,tag2=true;

    for(int i=0;i<resourceNum;i++){

        if(need[requestProcess-1][i]>=request[i]){

            tag1=true;
        }
        else {
            tag1=false;
            break;
        }
    }

    for(int i=0;i<resourceNum;i++){
            if(available[i]>=request[i]){

                tag2=true;
            }
            else{
                    tag2=false;
                    break;
            }

    }

    if(tag1==true && tag2==true){
        for(int i=0;i<resourceNum;i++){
            need[requestProcess-1][i]=need[requestProcess-1][i]-request[i];
            allocation[requestProcess-1][i]+=request[i];
            available[i]=available[i]-request[i];
        }

    }

    if(tag1==false||tag2==false){
        cout<<requestProcess<<" is unsafe state "<<endl;
    }

    int indexOfStore=0;

    for(int i=0;i<processNum;i++){

        for(int j=0;j<resourceNum;j++){

            if(need[i][j]<=available[i]){
                tag=true;
            }
            else {
                tag = false;
                break;
            }
        }

        if(tag==false){

            indexOfallo.push_back(i);



            tag=true;
        }

        else{

            string stringTemp;
            stringTemp = numberToString(i);
            stringTemp  = " P"+stringTemp;

            vecstr.push_back(stringTemp);

            for(int j=0;j<resourceNum;j++){

                available[j] = available[j]+allocation[i][j];
             }
        }

    }



    vector<int>:: iterator it;

    for(it=indexOfallo.begin();it!=indexOfallo.end();it++){
        int index = *it;

            string stringTemp1;
            stringTemp1 = numberToString(*it);
            stringTemp1 = " P"+stringTemp1;
            vecstr.push_back(stringTemp1);

        for(int j=0;j<resourceNum;j++){

            if(need[index][j]<=available[j]){
                tag=true;
            }
            else {
                tag = false;
                break;
            }
        }

        if(tag==true){
            for(int j=0;j<resourceNum;j++){
               available[j] = available[j]+allocation[index][j];
            }
        }

        else tag=true;
    }

    cout<<"creating new need number"<<endl;


    for(int i=0;i<processNum;i++){

        for(int j=0;j<resourceNum;j++){


            cout<<need[i][j]<<" ";

        }
        cout<<endl;
    }

    cout<<"new allocation"<<endl;

    for(int i=0;i<processNum;i++){

        for(int j=0;j<resourceNum;j++){


            cout<<allocation[i][j]<<" ";

        }
        cout<<endl;
    }

    vector<string>:: iterator that;
    cout<<"now the state is safe  ....."<<endl;
    cout<<"The sequence process is:"<<endl;
    for(that=vecstr.begin();that!=vecstr.end();that++){

        cout<<*that<<endl;
    }

    cout<<endl;
    cout<<"remaining work or available is :";

    for(int i=0;i<resourceNum;i++){
        cout<<available[i]<<"  ";
    }
	cout<<endl;

}
