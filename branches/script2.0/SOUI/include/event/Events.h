/**
* Copyright (C) 2014-2050 
* All rights reserved.
* 
* @file       Events.h
* @brief      
* @version    v1.0      
* @author     SOUI group   
* @date       2014/08/02
* 
* Describe    SOUI系统中使用的事件系统
*/

#pragma once

#include "core/Sobject.h"

namespace SOUI
{
    class SWindow;

    /*!
    \brief
    Base class used as the argument to all subscribers Event object.

    The base EventArgs class does not contain any useful information, it is intended
    to be specialised for each type of event that can be generated by objects within
    the system.  The use of this base class allows all event subscribers to have the
    same function signature.

    The \a handled field is used to signal whether an event was actually handled or not.  While
    the event system does not look at this value, code at a higher level can use it to determine
    how far to propagate an event.
    */
    class SOUI_EXP EventArgs
    {
    public:
        /*************************************************************************
        Construction
        *************************************************************************/
        EventArgs(SObject *pSender);

        virtual ~EventArgs(void) {}
        virtual UINT GetEventID()= 0;

        /*************************************************************************
        Data members
        *************************************************************************/
        
        UINT handled; /**< handlers should increment this if they handled the event. */

        int  idFrom; /**< 事件发送者ID */
        LPCWSTR nameFrom; /**< 事件发送者name */

        SObject *sender;  /**< 产生事件的原始SOUI对象，可能和idFrom and nameFrom指定的对象不同 */
    };

    enum SOUI_EVENTS
    {
        EVT_MOUSE_HOVER=9000,//两个窗口鼠标状态事件
        EVT_MOUSE_LEAVE,

        EVT_CMD=10000,
        EVT_CTXMENU,
        EVT_SETFOCUS,
        EVT_KILLFOCUS,
        EVT_DESTROY,
        EVT_VISIBLECHANGED,
        EVT_STATECHANGED,

        //增加两个滚动VIEW的事件
        EVT_SCROLLVIEW_ORIGINCHANGED,
        EVT_SCROLLVIEW_SIZECHANGED,

        EVT_SCROLL,
        EVT_OFEVENT,    //消息二次包装
        EVT_OFPANEL,    //一个itemPanel中的消息的二次包装

        //增加3个itempanel相关的事件,经过EVT_OFPANEL到达应用层
        EVT_ITEMPANEL_CLICK,
        EVT_ITEMPANEL_DBCLICK,
        EVT_ITEMPANEL_RCLICK,

        EVT_TAB_SELCHANGING=11000,
        EVT_TAB_SELCHANGED,
        EVT_TAB_ITEMHOVER,
        EVT_TAB_ITEMLEAVE,

        EVT_LB_GETDISPINFO=12000,
        EVT_LB_SELCHANGING,
        EVT_LB_SELCHANGED,

        EVT_LC_SELCHANGING=13000,
        EVT_LC_SELCHANGED,
		EVT_LC_ITEMDELETED,

        EVT_TB_GETDISPINFO=14000,    
        EVT_TB_SELCHANGING,
        EVT_TB_SELCHANGED,
        EVT_TB_QUERYITEMHEIGHT,

        EVT_TC_SELCHANGING=15000,
        EVT_TC_SELCHANGED,
        EVT_TC_EXPAND,
        EVT_TC_CHECKSTATE,
        EVT_TC_DBCLICK,    //treectrl的叶子节点双击事件, add by zhaosheng

        EVT_RE_NOTIFY=16000,

        EVT_SLIDER_POS=17000,

        EVT_HEADER_CLICK=18000,
        EVT_HEADER_ITEMCHANGING,
        EVT_HEADER_ITEMCHANGED,
        EVT_HEADER_ITEMSWAP,

        EVT_CB_SELCHANGE=19000,
        EVT_CBE_OFITEM=19500,
        
        EVT_CALENDAR_SELDAY=20000,

        EVT_EXTERNAL_BEGIN=10000000,
    };

    class SOUI_EXP EventCmnArgs : public EventArgs
    {
    public:
        EventCmnArgs(SObject *pSender,UINT uEvtID):EventArgs(pSender),uID(uEvtID)
        {

        }
        virtual UINT GetEventID(){return uID;}

    protected:
        UINT uID;
    };

    class SOUI_EXP EventCmd : public EventArgs
    {
    public:
        EventCmd(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_CMD};
        virtual UINT GetEventID(){return EventID;}
    };

    class SOUI_EXP EventCtxMenu : public EventArgs
    {
    public:
        EventCtxMenu(SObject *pSender):EventArgs(pSender),bCancel(FALSE){}
        enum{EventID=EVT_CTXMENU};
        virtual UINT GetEventID(){return EventID;}
        POINT           pt;
        BOOL            bCancel;
    };

    class SOUI_EXP EventSetFocus : public EventArgs
    {
    public:
        EventSetFocus(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_SETFOCUS};
        virtual UINT GetEventID(){return EventID;}
    };

    class SOUI_EXP EventKillFocus : public EventArgs
    {
    public:
        EventKillFocus(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_KILLFOCUS};
        virtual UINT GetEventID(){return EventID;}
    };
    
    class SOUI_EXP EventStateChanged : public EventArgs
    {
    public:
        EventStateChanged(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_STATECHANGED};
        virtual UINT GetEventID(){return EventID;}

        DWORD dwOldState;
        DWORD dwNewState;
    };
    
    class SOUI_EXP EventScrollViewOriginChanged : public EventArgs
    {
    public:
        EventScrollViewOriginChanged(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_SCROLLVIEW_ORIGINCHANGED};
        virtual UINT GetEventID(){return EventID;}

        CPoint ptOldOrigin;
        CPoint ptNewOrigin;
    };

    class SOUI_EXP EventScrollViewSizeChanged : public EventArgs
    {
    public:
        EventScrollViewSizeChanged(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_SCROLLVIEW_SIZECHANGED};
        virtual UINT GetEventID(){return EventID;}

        CSize szOldViewSize;
        CSize szNewViewSize;
    };

    class SOUI_EXP EventScroll : public EventArgs
    {
    public:
        EventScroll(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_SCROLL};
        virtual UINT GetEventID(){return EventID;}
        UINT        uSbCode;
        int         nPos;
        BOOL        bVertical;
    };

    class SOUI_EXP EventOfEvent : public EventArgs
    {
    public:
        EventOfEvent(SObject *pSender,EventArgs *_pOrgEvt)
            :EventArgs(pSender)
            ,pOrgEvt(_pOrgEvt)
        {}
        enum{EventID=EVT_OFEVENT};
        virtual UINT GetEventID(){return EventID;}
        EventArgs * pOrgEvt;
    };

    class SItemPanel;
    class SOUI_EXP EventOfPanel : public EventArgs
    {
    public:
        EventOfPanel(SItemPanel *_pPanel,EventArgs *_pOrgEvt);
        enum{EventID=EVT_OFPANEL};
        virtual UINT GetEventID(){return EventID;}

        SItemPanel *pPanel;
        EventArgs * pOrgEvt;
    };
    
    class SOUI_EXP EventOfComoboxExItem : public EventArgs
    {
    public:
        EventOfComoboxExItem(SObject *pSender,EventCmd *_pOrgEvt);
        enum{EventID=EVT_CBE_OFITEM};
        virtual UINT GetEventID(){return EventID;}

        EventCmd    *  pOrgEvt;
        BOOL           bCancel;
    };
    
    class SOUI_EXP EventTabSelChanging : public EventArgs
    {
    public:
        EventTabSelChanging(SObject *pSender):EventArgs(pSender),bCancel(FALSE){}
        enum{EventID=EVT_TAB_SELCHANGING};
        virtual UINT GetEventID(){return EventID;}
        UINT        uOldSel;
        UINT        uNewSel;
        BOOL        bCancel;
    };

    class SOUI_EXP EventTabSelChanged : public EventArgs
    {
    public:
        EventTabSelChanged(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_TAB_SELCHANGED};
        virtual UINT GetEventID(){return EventID;}
        UINT        uOldSel;
        UINT        uNewSel;
    };

    class SOUI_EXP EventTabItemHover : public EventArgs
    {
    public:
        EventTabItemHover(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_TAB_ITEMHOVER};
        virtual UINT GetEventID(){return EventID;}
        int iHover;
    };

    class SOUI_EXP EventTabItemLeave : public EventArgs
    {
    public:
        EventTabItemLeave(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_TAB_ITEMLEAVE};
        virtual UINT GetEventID(){return EventID;}
        int iLeave;
    };

    class SOUI_EXP EventLBGetDispInfo : public EventArgs
    {
    public:
        EventLBGetDispInfo(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_LB_GETDISPINFO};
        virtual UINT GetEventID(){return EventID;}
        int  iItem;
        SWindow * pItem;
        BOOL bSel;
        BOOL bHover;
    };

    class SOUI_EXP EventLBSelChanging : public EventArgs
    {
    public:
        EventLBSelChanging(SObject *pSender):EventArgs(pSender),bCancel(FALSE){
        
        }
        enum{EventID=EVT_LB_SELCHANGING};
        virtual UINT GetEventID(){return EventID;}
        int nNewSel;
        int nOldSel;
        BOOL bCancel;
    };

    class SOUI_EXP EventLBSelChanged : public EventArgs
    {
    public:
        EventLBSelChanged(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_LB_SELCHANGED};
        virtual UINT GetEventID(){return EventID;}
        int nNewSel;
        int nOldSel;
    };

    class SOUI_EXP EventTBGetDispInfo : public EventArgs
    {
    public:
        EventTBGetDispInfo(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_TB_GETDISPINFO};
        virtual UINT GetEventID(){return EventID;}
        HSTREEITEM  hItem;
        SWindow     *pItemWnd;
        BOOL        bSel;
        BOOL        bHover;
    };

    class SOUI_EXP EventTBSelChanging: public EventArgs
    {
    public:
        EventTBSelChanging(SObject *pSender):EventArgs(pSender),bCancel(FALSE){}
        enum{EventID=EVT_TB_SELCHANGING};
        virtual UINT GetEventID(){return EventID;}
        HSTREEITEM hNewSel;
        HSTREEITEM hOldSel;
        BOOL        bCancel;
    };

    class SOUI_EXP EventTBSelChanged: public EventArgs
    {
    public:
        EventTBSelChanged(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_TB_SELCHANGED};
        virtual UINT GetEventID(){return EventID;}
        HSTREEITEM hNewSel;
        HSTREEITEM hOldSel;
    };
    
    class SOUI_EXP EventTBQueryItemHeight : public EventArgs
    {
    public:
        EventTBQueryItemHeight(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_TB_QUERYITEMHEIGHT};
        virtual UINT GetEventID(){return EventID;}
        HSTREEITEM hItem;
        DWORD      dwState;    //状态,和SWindow::GetState的值一致
        int        nItemHeight;//返回值保存到这里
    };

    class SOUI_EXP EventRENotify : public EventArgs
    {
    public:
        EventRENotify(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_RE_NOTIFY};
        virtual UINT GetEventID(){return EventID;}
        DWORD iNotify;
        LPVOID pv;
        HRESULT hr;
    };

    class SOUI_EXP EventSliderPos : public EventArgs
    {
    public:
        EventSliderPos(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_SLIDER_POS};
        virtual UINT GetEventID(){return EventID;}
        int     nPos;
    };

    //点击表头
    class SOUI_EXP EventHeaderClick : public EventArgs
    {
    public:
        EventHeaderClick(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_HEADER_CLICK};
        virtual UINT GetEventID(){return EventID;}
        int   iItem;
    };

    //点击表头
    class SOUI_EXP EventHeaderItemChanging : public EventArgs
    {
    public:
        EventHeaderItemChanging(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_HEADER_ITEMCHANGING};
        virtual UINT GetEventID(){return EventID;}
        int   iItem;
        int   nWidth;
    };

    //点击表头
    class SOUI_EXP EventHeaderItemChanged : public EventArgs
    {
    public:
        EventHeaderItemChanged(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_HEADER_ITEMCHANGED};
        virtual UINT GetEventID(){return EventID;}
        int   iItem;
        int   nWidth;
    };

    //拖动表项调整位置
    class SOUI_EXP EventHeaderItemSwap : public EventArgs
    {
    public:
        EventHeaderItemSwap(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_HEADER_ITEMSWAP};
        virtual UINT GetEventID(){return EventID;}
        int   iOldIndex;
        int      iNewIndex;
    };

    class SOUI_EXP EventCBSelChange : public EventArgs
    {
    public:
        EventCBSelChange(SObject *pSender,int _nCurSel):EventArgs(pSender),nCurSel(_nCurSel){}
        enum{EventID=EVT_CB_SELCHANGE};
        virtual UINT GetEventID(){return EventID;}
        int nCurSel;
    };

    class SOUI_EXP EventLCSelChanging : public EventArgs
    {
    public:
        EventLCSelChanging(SObject *pSender):EventArgs(pSender),bCancel(FALSE){}
        enum{EventID=EVT_LC_SELCHANGING};
        virtual UINT GetEventID(){return EventID;}
        int nNewSel;
        int nOldSel;
        BOOL bCancel;
    };

    class SOUI_EXP EventLCSelChanged : public EventArgs
    {
    public:
        EventLCSelChanged(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_LC_SELCHANGED};
        virtual UINT GetEventID(){return EventID;}
        int nNewSel;
        int nOldSel;
    };

	class SOUI_EXP EventLCItemDeleted : public EventArgs
	{
	public:
		EventLCItemDeleted(SObject *pSender) :EventArgs(pSender){}
		enum{ EventID = EVT_LC_ITEMDELETED };
		virtual UINT GetEventID(){ return EventID; }
		
		int		nItem;
		DWORD   dwData;
	};

    class SOUI_EXP EventCalendarSelDay : public EventArgs
    {
    public:
        EventCalendarSelDay(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_CALENDAR_SELDAY};
        virtual UINT GetEventID(){return EventID;}
        WORD   wOldDay;
        WORD   wNewDay;
    };


    class SOUI_EXP EventTCSelChanging : public EventArgs
    {
    public:
        EventTCSelChanging(SObject *pSender):EventArgs(pSender),bCancel(FALSE){}
        enum{EventID=EVT_TC_SELCHANGING};
        virtual UINT GetEventID(){return EventID;}
        HSTREEITEM hOldSel;
        HSTREEITEM hNewSel;
        BOOL bCancel;
    };

    class SOUI_EXP EventTCSelChanged : public EventArgs
    {
    public:
        EventTCSelChanged(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_TC_SELCHANGED};
        virtual UINT GetEventID(){return EventID;}
        HSTREEITEM hOldSel;
        HSTREEITEM hNewSel;
    };

    class SOUI_EXP EventTCCheckState : public EventArgs
    {
    public:
        EventTCCheckState(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_TC_CHECKSTATE};
        virtual UINT GetEventID(){return EventID;}
        HSTREEITEM  hItem;
        UINT        uCheckState;
    };

    class SOUI_EXP EventTCExpand : public EventArgs
    {
    public:
        EventTCExpand(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_TC_EXPAND};
        virtual UINT GetEventID(){return EventID;}
        HSTREEITEM  hItem;
        BOOL bCollapsed;
    };

    //双击treectrl的叶子节点 add by zhaosheng
    class SOUI_EXP EventTCDbClick : public EventArgs
    {
    public:
        EventTCDbClick(SObject *pSender):EventArgs(pSender){}
        enum{EventID=EVT_TC_DBCLICK};
        virtual UINT GetEventID(){return EventID;}
        HSTREEITEM hItem;  //双击选中的节点
    };

} // End of  CEGUI namespace section