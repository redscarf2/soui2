#pragma once
#include "ScintillaWnd.h"
#include "Scintilla.h"

namespace SOUI
{
	class SMoveWnd;

	class SDesignerView
	{
	private:
		CAutoRefPtr<SStylePool> m_privateStylePool; /**<�ֲ�style pool*/
		CAutoRefPtr<SSkinPool>  m_privateSkinPool;  /**<�ֲ�skin pool*/
	public:
        SDesignerView(SHostDialog *pMainHost, SWindow *pContainer, STreeCtrl *pTreeXmlStruct);
		~SDesignerView();
		 
		 SMoveWnd* m_CurSelCtrl;  //�û���ǰѡ��Ŀؼ�
		 SList<SWindow*> m_CopyList;  

		 //���浱ǰ�򿪵Ĳ����ļ�
		 BOOL SaveLayoutFile();
		 BOOL SaveAll();

		 //�رյ�ǰ�򿪵Ĳ����ļ�
		 BOOL CloseLayoutFile();

         BOOL OpenProject(SStringT strFileName);// �򿪹���

		 BOOL InsertLayoutToMap(SStringT);

		 BOOL NewLayout(SStringT strResName, SStringT strPath);  //�½�dialog ��include����

		 BOOL LoadLayout(SStringT strFileName);   //���ز���

		 //����Root����
		 SMoveWnd* CreateWnd(SWindow *pContainer,LPCWSTR pszXml);
         void CreateAllChildWnd(SWindow *pRealWnd, SMoveWnd *pMoveWnd);
         void UpdateAllLayout(SMoveWnd* pMoveWndRoot);

		 //������ÿһ���ؼ�������
		 void RenameChildeWnd(pugi::xml_node xmlNode);
         void RenameWnd(pugi::xml_node xmlNode, BOOL force = FALSE);
         void RenameAllLayoutWnd();
		 void RemoveWndName(pugi::xml_node xmlNode,BOOL bClear, SStringT strFileName = _T(""));

		 void UpdatePosToXmlNode(SWindow *pRealWnd, SMoveWnd* pMoveWnd);//�ƶ��ؼ���ͬʱ���ؼ�λ��д��xml�ڵ�

		 //������
		 void Debug(pugi::xml_node);
		 void Debug(SStringT str);
		 SStringT Debug1(pugi::xml_node);

		 SStringT NodeToStr(pugi::xml_node xmlNode);
		 SStringT NodeToStr(pugi::xml_document xmlNode);

		 void SetCurrentCtrl(pugi::xml_node xmlNode, SMoveWnd *pWnd); //���õ�ǰѡ�еĿؼ�

         SStringW GetPosFromLayout(SwndLayout *pLayout, INT nPosIndex);

		 //ͨ���ؼ�������ֵ�ҵ��ÿؼ���Ӧ��xml�ڵ�
		 pugi::xml_node FindNodeByAttr(pugi::xml_node NodeRoot, SStringT attrName, SStringT attrValue);

		 void InitProperty(SWindow *pPropertyContainer);   //��ʼ�������б�
		 void InitCtrlProperty(pugi::xml_node NodeCom, pugi::xml_node NodeCtrl);

		 void CreatePropGrid(SStringT strCtrlType);
		 void UpdatePropGrid(pugi::xml_node xmlNode);

		 bool OnPropGridValueChanged( EventArgs *pEvt );
		 bool OnPropGridItemClick( EventArgs *pEvt );
		 bool OnTCSelChanged(EventArgs *pEvt);

		 

		 BOOL ReLoadLayout(); 
		 BOOL bIsContainerCtrl(SStringT strCtrlName); //�жϿؼ��Ƿ��������ؼ�

		 SMoveWnd* GetMoveWndRoot(){ return m_pMoveWndRoot;};
		 SWindow* GetRealWndRoot(){ return m_pRealWndRoot;};

		 void AddCodeToEditor(CScintillaWnd* pSciWnd);  //����xml���뵽����༭��
		 void GetCodeFromEditor(CScintillaWnd* pSciWnd);//�Ӵ���༭����ȡxml����

		 void SetSelCtrlNode(pugi::xml_node xmlNode);

		 void NewWnd(CPoint pt, SMoveWnd *pM);


		 void InitXMLStruct(pugi::xml_node xmlNode, HSTREEITEM item);
         BOOL GoToXmlStructItem(int data, HSTREEITEM item);

		 void DeleteCtrl();
		 void Preview();
		 void unPreview();

		 void RefreshRes();
		 void ShowZYGLDlg();
		 void ShowYSGLDlg();

		 void ShowMovWndChild(BOOL bShow, SMoveWnd* pMovWnd);

		 int GetIndexData();

		 SWindow* FindChildByUserData(SWindow* pWnd, int data);

		 
		 void TrimXmlNodeTextBlank(pugi::xml_node xmlNode);

	public:
		    SWindow *m_pRealWndRoot;       //������������;
		    SMoveWnd  *m_pMoveWndRoot; //���ִ��ڵĸ�����

			BOOL     m_bChange;    //�ļ��Ƿ��޸�,������޸���Ҫ����

			BOOL     m_bPage;      //�Ƿ�Ϊҳ�ļ�,����Ϊ�����ļ�

			CPoint   m_downPt;   //���µ�λ��

			INT     m_nState;    //�Ƿ����ڽ��д����ؼ�����궯���� 1:�ǣ�0:��

			SStringW *m_strxml;
			pugi::xml_node m_xmlNode;   //��ǰѡ�еĿؼ���xmlnode 

			pugi::xml_document m_xmlSelCtrlDoc;//���ѡ��ؼ��б�Ҫ�����Ŀؼ���xml

			pugi::xml_node m_xmlSelCtrlNode;  //���ѡ��ؼ��б�Ҫ�����Ŀؼ���xml

			SMap<SStringT, pugi::xml_node> m_mapLayoutFile;  
			SMap<SStringT, pugi::xml_document *> m_mapLayoutFile1;  
			//SMap<int, SStringT> m_mapInclude;    //����include�ڵ�
			SMap<SStringT, SMap<int, SStringT>* > m_mapInclude1;    //����ÿһ�������ļ���Ӧ��include map;

			SMap<SWindow*, SMoveWnd*> m_mapMoveRealWnd;

			SStringT m_strUIResFile;   //C:\demos\MyTest\uires\uires.idx
			SStringT m_strProPath;     //C:\demos\MyTest\uires\

			SStringT m_strCurFile; //��ǰ�򿪵Ĵ����ļ���  xml\main.xml
			SStringT m_strCurFileEditor; //��ǰ����༭���򿪴����Ӧ���ļ�  xml\main.xml

			//CAutoRefPtr<IResProvider>   pResProvider;
			SWindow *m_pContainer;  //���в��ִ��ڸ������� 
	        pugi::xml_node m_CurrentLayoutNode;

			SMap<SStringT, pugi::xml_document*> m_mapCtrlProperty;//���пؼ��������б� <Button, xmlnode> <Check, xmlNode>
			SWindow *m_pPropertyContainer;     //������常����

			SStringT m_strCurrentCtrlType; //��ǰѡ�еĿؼ����� "button" "check"�ȵ�
			SPropertyGrid *m_pPropgrid;    //�������
			SHostDialog* m_pMainHost;

			pugi::xml_document m_xmlDocUiRes;  //uires�ļ�


			SList<SStringT> m_lstSouiProperty;   //SOUI�ڵ�������б�  ��property.xml hostwnd�ڵ��ж���
			SList<SStringT> m_lstRootProperty;   //Root�ڵ�������б� 
            SList<SStringT> m_lstContainerCtrl;  //�����ؼ��б����������ؼ������治�ܰڷſؼ� ��Ctrl.xml�ж���

			STreeCtrl *m_treeXmlStruct; //��ʾxml�ĵ��ṹ��tree�ؼ�

			int m_ndata; //���ֵ������ʶxmlnode��ÿһ���ڵ㣬�ڵ�����Ϊdata,xmlnode���������ֵ��Ψһ��;


	};

}