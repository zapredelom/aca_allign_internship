#include <iostream>
class TemplateMethod{
    public:
    virtual void printPaper() final {
        setHeadline();
        setFooter();
        setImage();
        if(_isLocationNeeded)
         {
            setLocation();
         }
    };
    virtual void setHeadline() = 0;
    virtual void setFooter() = 0;
    virtual void setImage() = 0;
    virtual void setLocation() = 0;

    virtual bool isLocationNeeded() {return true;}
    protected:

    bool _isLocationNeeded;

};

class PritMusicianPoster : public TemplateMethod{
public:
    PritMusicianPoster(const std::string& name): _name(name) {
        _isLocationNeeded = false;
    }
    void setHeadline () override {
        std::cout<<"setting hedline for concert";
    }

    void setFooter(){
        std::cout<<_name<<std::endl;
    }

    virtual void setImage(){
        std::cout<<"setImage"<<std::endl;

    }
    virtual void setLocation() {
        std::cout<<"setLocation"<<std::endl;

    }
    bool isLocationNeeded() {
         return false;
    }
    private:
    std::string _name ;
};