#include <bits/stdc++.h>
using namespace std;

class KhachHang
{
    private:
        int maKH;
        string hoten;
        string sdt;
    public:
        KhachHang()
        {
            maKH = 0;
            hoten = "";
            sdt = "";
        }
        
        int getMa()
        {
            return maKH;
        }
        
        string getName()
        {
            return hoten;
        }

        string getSdt()
        {
            return sdt;
        }

        void setName(string name)
        {
            hoten = name;
        }

        void setSdt(string p)
        {
            sdt = p;
        }
        
        friend istream& operator >> (istream &is, KhachHang& kh)
        {
            cout << "Nhap ma KH: ";
            is >> kh.maKH;
            cout << "Nhap ho ten: ";
            cin.ignore();
            getline(is, kh.hoten);
            cout << "Nhap so dien thoai: ";
            is >> kh.sdt;

            return is;
        }
        
        friend ostream& operator << (ostream &os, KhachHang& kh)
        {
            os << endl << "Thong tin khach hang: ";
            os << kh.maKH << endl;
            os << kh.hoten << endl;
            os << kh.sdt << endl;

            return os;
        }
};

class quanlyKH
{
    private: 
        list<KhachHang> ds;
    public:
        void addKH(KhachHang kh)
        {
            list<KhachHang>::iterator it = ds.begin();
            while(it != ds.end() && it->getMa() < kh.getMa())
            {
                ++it;
            }

            if(it != ds.end() && it->getMa() == kh.getMa())
            {
                return;
            }

            ds.insert(it, kh);
        }

        list<KhachHang>::iterator getKH(int maCanTim)
        {
            int l = 0;
            int r = ds.size() - 1;
            
            while(l <= r)
            {
                int mid = (l + r) / 2;
                auto it = ds.begin();
                advance(it , mid);
                int maGiua = it->getMa();

                if(maGiua == maCanTim)
                { 
                    return it;
                }
                else if(maGiua < maCanTim) l = mid + 1;
                else r = mid - 1;
            }

            return ds.end();
        }
        
        void menuKH()
        {
            list<KhachHang>::iterator it = ds.end();
            int ma;
            cout << "Nhap ma KH can tim: ";
            cin >> ma;

            it = getKH(ma);

            int menu;
            string hoten = "";
            string sdt = "";
            
            if(ds.end() != it)
            {
                cout << "Chon xoa[1]/sua[2] thong tin KH: ";
                cin >> menu;
                
                if(menu == 1)
                {
                    ds.erase(it);
                }
                else if(menu == 2)
                {
                    cout << "Sua ho ten: ";
                    cin.ignore();
                    getline(cin, hoten);
                    it->setName(hoten);
                    
                    cout << "Sua so dien thoai: ";
                    cin >> sdt;
                    it->setSdt(sdt);
                }
            }
            else
            {
                cout << "Khong tim thay KH!";
            }
        }
        
        void inKH()
        {
            for(auto x : ds)
            {
                cout << x;
            }
        }
}; 

int main()
{
    int ma;
    quanlyKH ql;
    KhachHang a;   

    char ask;
    do
    {
        cin >> a;
        ql.addKH(a); 
        cout << "Co nhap them KH nua khong?";
        cin.ignore();
        cin >> ask;
    }
    while(ask == 'y');

    ql.menuKH();
    ql.inKH();

    return 0;
}