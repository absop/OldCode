#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class Frame : public wxFrame {
  public:
    Frame() : wxFrame(NULL, wxID_ANY, "PaintBoard",
        wxDefaultPosition, wxSize(480, 640),
        wxDEFAULT_FRAME_STYLE ^ wxMAXIMIZE_BOX ^ wxRESIZE_BORDER) {

        CentreOnScreen();
        SetBackgroundColour(wxColour("#FAFAFA"));

        Bind(wxEVT_PAINT, &OnPaint, this);
        Bind(wxEVT_MOTION, &OnLeftMove, this);
        Bind(wxEVT_KEY_DOWN, &OnKeyDown, this);
        Bind(wxEVT_LEFT_DOWN, &OnLeftDown,this);
        Bind(wxEVT_LEFT_UP, &OnLeftUp,this);
    }

    // 定义绘制函数
    void OnPaint( wxPaintEvent &event ) {
        wxPaintDC dc(this);

        wxFont font = dc.GetFont();
        dc.SetFont(wxFontInfo().FaceName(wxT("宋体")));
        dc.SetTextForeground(wxColour("#323232"));
        dc.DrawText(DirCaption, wxPoint(120, 100));

        dc.SetFont(font);
        dc.SetTextForeground(wxColour("#FF5370"));
        dc.DrawText(DirContent, wxPoint(200, 100));
    }

    void OnLeftMove( wxMouseEvent& event ) {
        if (isDown && event.Dragging()) {
            wxPoint currPos = event.GetPosition();
            wxClientDC dc(this);
            dc.SetPen(wxPen(wxColour("#7C4DFF"), 3, wxPENSTYLE_SOLID));
            dc.DrawLine(currPos, lastPos);
            dc.SetPen(wxNullPen);
            lastPos = currPos;
        }
    }
    void OnLeftDown( wxMouseEvent& event ) {
        lastPos = event.GetPosition();
        isDown = true;
    }
    void OnLeftUp( wxMouseEvent& event ) {
        isDown = false;
    }

    void OnKeyUp( wxKeyEvent& event ) {
        // DirCaption = wxT("松开了： ");
        // DirContent = GetKeyCodeString(event);
        // RefreshRect(wxRect(100, 100, 100, 20));
    }
    void OnKeyDown( wxKeyEvent& event ) {
        DirCaption = wxT("按下了： ");
        DirContent = GetKeyCodeString(event);
        RefreshRect(wxRect(120, 100, 150, 30));
    }

    wxString GetKeyCodeString( wxKeyEvent& event) {
        switch ( event.GetKeyCode() ) {
            case WXK_UP: return wxT("↑");
            case WXK_DOWN: return wxT("↓");
            case WXK_LEFT: return wxT("←");
            case WXK_RIGHT: return wxT("→");
            default:
                return wxString(event.GetUnicodeKey());
        }
    }

  private:
    bool isDown;     //记录鼠标是否处于按下状态
    wxPoint lastPos;  //鼠标位置

    wxString DirCaption;
    wxString DirContent;
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
