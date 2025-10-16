//------------------------------------//
//        CALCULADORA CODIGO          //
//------------------------------------//

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include<FL/Fl_Output.H>
#include<iostream>
#include<cmath>
#include<climits>
#include<sstream>
#include <ctime>

#define CEL 60
#define MAX_SOM 255

double val[MAX_SOM],resp,valf[MAX_SOM];
long long int casa=0,i=0,k=0;
int dcasa[MAX_SOM],mdcasa=-100;
char op[MAX_SOM];
bool isfloat[MAX_SOM];
Fl_Output* texto;
std::ostringstream text;


//LOGIC:
void delayed(std::string get_error);
void str_update(int j, std::string *str);
void getv(int v);
void getc(char c);
//NUMBERS:
void on_button_click(Fl_Widget*, void*);
void on_button_click1(Fl_Widget*, void*);
void on_button_click2(Fl_Widget*, void*);
void on_button_click3(Fl_Widget*, void*);
void on_button_click4(Fl_Widget*, void*);
void on_button_click5(Fl_Widget*, void*);
void on_button_click6(Fl_Widget*, void*);
void on_button_click7(Fl_Widget*, void*);
void on_button_click8(Fl_Widget*, void*);
void on_button_click9(Fl_Widget*, void*);
//OPERATIONS:
void on_button_click_AC(Fl_Widget*, void*);
void on_button_click_DC(Fl_Widget*, void*);
void on_button_click_div(Fl_Widget*, void*);
void on_button_click_plus(Fl_Widget*, void*);
void on_button_click_pow(Fl_Widget*, void*);
void on_button_click_sqrt(Fl_Widget*, void*);
void on_button_click_minus(Fl_Widget*, void*);
void on_button_click_mult(Fl_Widget*, void*);
void on_button_click_equal(Fl_Widget*, void*);
void on_button_click_float(Fl_Widget*, void*);



int main() {
    isfloat[0]=false;
    resp=0;
    val[0]=0;
    dcasa[0]=1;
    const int cel=CEL;

    Fl_Window* window = new Fl_Window(cel*4, cel*6, "Minha Calculadora");
    texto = new Fl_Output(0, 0, cel*4, cel, "");
    texto->value("0");

    Fl_Button* button_AC = new Fl_Button(0, cel, cel, cel, "AC");
    Fl_Button* button_DC = new Fl_Button(cel, cel, cel, cel, "DC");
    Fl_Button* button_pow = new Fl_Button(cel*2, cel, cel, cel, "^x");
    Fl_Button* button_sqrt = new Fl_Button(cel*3, cel, cel, cel, "^1/x");

    Fl_Button* button = new Fl_Button(0, cel*2, cel, cel, "0");
    Fl_Button* button1 = new Fl_Button(cel, cel*2, cel, cel, "1");
    Fl_Button* button2 = new Fl_Button(cel*2, cel*2, cel, cel, "2");
    Fl_Button* button_plus = new Fl_Button(cel*3, cel*2, cel, cel, "+");

    Fl_Button* button3 = new Fl_Button(0, cel*3, cel, cel, "3");
    Fl_Button* button4 = new Fl_Button(cel, cel*3, cel, cel, "4");
    Fl_Button* button5 = new Fl_Button(cel*2, cel*3, cel, cel, "5");
    Fl_Button* button_minus = new Fl_Button(cel*3, cel*3, cel, cel, "-");

    Fl_Button* button6 = new Fl_Button(0, cel*4, cel, cel, "6");
    Fl_Button* button7 = new Fl_Button(cel, cel*4, cel, cel, "7");
    Fl_Button* button8 = new Fl_Button(cel*2, cel*4, cel, cel, "8");
    Fl_Button* button_div = new Fl_Button(cel*3, cel*4, cel, cel, "/");

    Fl_Button* button9 = new Fl_Button(cel, cel*5, cel, cel, "9");
    Fl_Button* button_equal = new Fl_Button(0, cel*5, cel, cel, "=");
    Fl_Button* button_float = new Fl_Button(cel*2, cel*5, cel, cel, ".");
    Fl_Button* button_mult = new Fl_Button(cel*3, cel*5, cel, cel, "x");


    button->callback(on_button_click);
    button1->callback(on_button_click1);
    button2->callback(on_button_click2);
    button3->callback(on_button_click3);
    button4->callback(on_button_click4);
    button5->callback(on_button_click5);
    button6->callback(on_button_click6);
    button7->callback(on_button_click7);
    button8->callback(on_button_click8);
    button9->callback(on_button_click9);

    button_AC->callback(on_button_click_AC);
    button_DC->callback(on_button_click_DC);
    button_div->callback(on_button_click_div);
    button_plus->callback(on_button_click_plus);
    button_pow->callback(on_button_click_pow);
    button_sqrt->callback(on_button_click_sqrt);
    button_minus->callback(on_button_click_minus);
    button_mult->callback(on_button_click_mult);
    button_equal->callback(on_button_click_equal);
    button_float->callback(on_button_click_float);


    window->end();
    window->show();
    return Fl::run();
}

void limpar_apos_erro(void*) {
    on_button_click_DC(nullptr, nullptr);
}

void delayed(std::string get_error) {
    texto->value(get_error.c_str());
    Fl::add_timeout(1.0, limpar_apos_erro);
}

void str_update(int j, std::string *str){
    if(dcasa[j]-1 > mdcasa){
        mdcasa=dcasa[j]-1;
    }
    std::ostringstream getv;

    getv.precision(dcasa[j]-1);
    getv<< std::fixed << val[j];
    
    *str+=getv.str();
    getv.str("");
    getv.clear();
}

void getv(int v){
    if(isfloat[i]==false){
    val[i]=val[i]*10+v;
    if(val[i]!=0) casa++;
    text.precision(0);
    text<<std::fixed<<val[i];
    texto->value(text.str().c_str());
    text.str("");
    text.clear();

    }if(isfloat[i]==true){
        val[i]=val[i]+(v/pow(10,dcasa[i]));
        text.precision(dcasa[i]);
        text<<std::fixed<<val[i];
        texto->value(text.str().c_str());
        text.str("");
        text.clear();
        dcasa[i]++;
    }
}
void getc(char c){
    op[k]=c;
    k++;
    i++;
    val[i]=0;
    isfloat[i]=false;
    dcasa[i]=1;
}


void on_button_click(Fl_Widget*, void*) {
    getv(0);
}
void on_button_click1(Fl_Widget*, void*) {
    getv(1);
}
void on_button_click2(Fl_Widget*, void*) {
    getv(2);
    
}
void on_button_click3(Fl_Widget*, void*) {
    getv(3);
}
void on_button_click4(Fl_Widget*, void*) {
    getv(4);
}
void on_button_click5(Fl_Widget*, void*) {
    getv(5);
}
void on_button_click6(Fl_Widget*, void*) {
    getv(6);
}
void on_button_click7(Fl_Widget*, void*) {
    getv(7);
}
void on_button_click8(Fl_Widget*, void*) {
    getv(8);
}
void on_button_click9(Fl_Widget*, void*) {
    getv(9);
}

void on_button_click_AC(Fl_Widget*, void*) {
    if (isfloat[i] == false) {
        val[i] = (int)(val[i] / 10);
        casa--;
    } else {
        if (dcasa[i] > 0) {
            val[i] = ((int)(val[i] * pow(10, dcasa[i]) / 10)) / pow(10, dcasa[i]);
            dcasa[i]--;
        }
    }

    text.str("");
    text.clear();
    text.precision(0);
    text << std::fixed << val[i];
    texto->value(text.str().c_str());
    text.str("");
    text.clear();
}

void on_button_click_DC(Fl_Widget*, void*) {
    for(int j=0; j <= i; j++){
        val[j]=0;
    }
    for(int j=0; j <= k; j++){
        op[j]='\0';
    }
    i=0;
    k=0;
    resp=0;
    texto->value("0");
}
void on_button_click_div(Fl_Widget*, void*) {
    getc('/');
}
void on_button_click_plus(Fl_Widget*, void*) {
    getc('+');
}
void on_button_click_minus(Fl_Widget*, void*) {
    getc('-');
}
void on_button_click_mult(Fl_Widget*, void*) {
    getc('*');
}
void on_button_click_pow(Fl_Widget*, void*) {
    getc('^');
}
void on_button_click_sqrt(Fl_Widget*, void*) {
    getc('s');
}
void on_button_click_equal(Fl_Widget*, void*) {
    bool float_resp=false,add_h=true;
    std::string str;
    resp=val[0];

    str_update(0, &str);

    val[0]=0;

    for(int j=1; j <= i;j++){
        add_h=true;
        switch (op[j-1])
        {
        case '+':
                str+='+';
                str_update(j, &str);
                if(isfloat[j]){float_resp=true;}
                resp+=val[j];
                val[j]=0;
            break;
        case '-':
                str+='-';
                str_update(j, &str);

                resp-=val[j];
                val[j]=0;
            break;
        case '*':
                str+='*';
                str_update(j, &str);

                resp*=val[j];
                val[j]=0;
            break;
        case '/':
                str+='/';
                str_update(j, &str);

                val[j]=0;
                if(add_h){
                mdcasa+=2;
                add_h=false;
                }
                if (val[j] != 0) {
                    resp /=val[j];
                }else{
                    
                    return delayed("ERRO:divisão por zero");
                }
            break;
        case '^':
                resp=pow(resp,val[j]);
                str+='^';
                str_update(j, &str);
                val[j]=0;
            break;
        case 's':
                str="sq("+str+",";
                str_update(j, &str);
                str+=")";
                val[j]=0;
                if(add_h){
                mdcasa+=2;
                add_h=false;
                }
                if (val[j] != 0) {
                    resp = pow(resp, 1.0 / val[j]);
                } else {
                    return delayed("ERRO:raiz inexistente");
                }
            break;
        }
        if (resp > std::numeric_limits<double>::max() || resp < -std::numeric_limits<double>::max()) {
            return delayed("ERRO: resultado fora do esperado");
        }
    }
    std::ostringstream oss;
    if((int)(resp*pow(10,mdcasa))%(int)pow(10,mdcasa)== 0 || float_resp){
        oss.precision(0);
    }else{
        oss.precision(mdcasa);
    }
    oss << std::fixed << resp;
    texto->value((str + " = " + oss.str()).c_str());
    val[0]=resp;
    i=1;
    for(int j=0; j <= k; j++){
        op[j]='\0';
    }
    k=0;
}
void on_button_click_float(Fl_Widget*, void*){
    text.precision(0);
    text<<std::fixed<<val[i];
    isfloat[i]=true;
    texto->value((text.str()+".").c_str());
    text.str("");
    text.clear();
}
