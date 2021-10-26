#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/grid.h>


void CreateTable(wxWindow *parent) {
    wxString attr[] = {
        wxT("姓名"), wxT("年龄"), wxT("性别"), wxT("身高"), wxT("体重")
    };
    wxGrid *grid = new wxGrid(parent, wxID_ANY,
                              wxPoint(0, 0), wxSize(580, 310));
    grid->CreateGrid(8, 5);
    grid->SetDefaultRowSize(35);
    grid->SetDefaultColSize(100);
    grid->SetLabelBackgroundColour(0x228B22);
    grid->SetLabelTextColour(0xFFFFFF);
    grid->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_CENTRE);
    // for (int i = 0; i < 5; i++)
    //     grid->SetColLabelValue(i, attr[i]);
    parent->Fit();
}


class Frame : public wxFrame {
  public:
    Frame() : wxFrame(NULL, wxID_ANY, "GridCell",
                          wxDefaultPosition, wxSize(480, 640),
                          wxDEFAULT_FRAME_STYLE ^ wxMAXIMIZE_BOX ^ wxRESIZE_BORDER) {

        CentreOnScreen();
        SetBackgroundColour(wxColour("#FAFAFA"));

        CreateTable(this);
        Bind(wxEVT_PAINT, &OnPaint, this);
    }

    // 定义绘制函数
    // void OnPaint( wxPaintEvent &event ) {
    //     wxPaintDC dc(this);

    //     wxFont font = dc.GetFont();
    //     dc.SetFont(wxFontInfo().FaceName(wxT("宋体")));
    //     dc.SetTextForeground(wxColour("#323232"));
    //     dc.DrawText(DirCaption, wxPoint(120, 100));

    //     dc.SetFont(font);
    //     dc.SetTextForeground(wxColour("#FF5370"));
    //     dc.DrawText(DirContent, wxPoint(200, 100));
    // }
};


class wxPaintBoard : public wxApp {
  public:
    virtual bool OnInit() {
        Frame *frame = new Frame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(wxPaintBoard);
