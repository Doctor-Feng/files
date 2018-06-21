
// MFCApplication6Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "MFCApplication6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication6Dlg �Ի���



CMFCApplication6Dlg::CMFCApplication6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication6Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_K_ROWS2, Edit_K_pers);
	DDX_Control(pDX, IDC_K_ROWS, Edit_K_rows);
	DDX_Control(pDX, IDC_K_COLS, Edit_K_cols);
	DDX_Control(pDX, IDC_STATIC5, m_Label_5);
	DDX_Control(pDX, IDC_STATIC6, m_label_6);
	DDX_Control(pDX, IDC_STATIC7, m_label_7);
	DDX_Control(pDX, IDC_STATIC8, m_label_8);
	DDX_Control(pDX, IDC_STATIC9, m_label_9);
	DDX_Control(pDX, IDC_STATIC10, m_label_10);
}

BEGIN_MESSAGE_MAP(CMFCApplication6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication6Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_SMALL_K, &CMFCApplication6Dlg::OnBnClickedSmallK)
END_MESSAGE_MAP()


// CMFCApplication6Dlg ��Ϣ�������

BOOL CMFCApplication6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	
	//��ͼ��ʾ����
	CStatic *pStatic = (CStatic*)GetDlgItem(IDC_STATIC_PIC);
	CRect lRect;
	pStatic->GetClientRect(&lRect);
	pStatic->GetDC()->FillSolidRect(lRect.left, lRect.top, lRect.Width(), lRect.Height(), RGB(240, 240, 240));
	HWND hImgWnd = GetDlgItem(IDC_STATIC_PIC)->m_hWnd;

	OpenWindow(lRect.left, lRect.top, lRect.Width(), lRect.Height(), (Hlong)hImgWnd, "visible", "", &hv_WindleHandle);


	//��СKͼ��ʾ����
	CStatic *pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC_PIC2);
	CRect lRect2;
	pStatic2->GetClientRect(&lRect2);
	pStatic2->GetDC()->FillSolidRect(lRect2.left, lRect2.top, lRect2.Width(), lRect2.Height(), RGB(240, 240, 240));
	HWND hImgWnd2 = GetDlgItem(IDC_STATIC_PIC2)->m_hWnd;

	OpenWindow(lRect2.left, lRect2.top, lRect2.Width(), lRect2.Height(), (Hlong)hImgWnd2, "visible", "", &hv_WindleHandle2);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication6Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CString pcsun = _T("ͼƬ�ļ�(*.bmp *.png *.jpg)|*.bmp; *.png; *.jpg|All Files(.)|.*||");
	CFileDialog OpenDialog(TRUE, NULL, 0, OFN_OVERWRITEPROMPT, pcsun, NULL);
	if (OpenDialog.DoModal() == IDCANCEL) return;
	//���ش��ļ�����·���������ݸ��༭�ؼ����� 
	CString str = OpenDialog.GetPathName();


	// ���ں��֣���Ҫת��
	char szFileNameA[256];
	TCHAR szFileNameW[256];
	lstrcpy(szFileNameW, str);
	WideCharToMultiByte(CP_ACP, 0, szFileNameW, 256, szFileNameA, 256, NULL, NULL);

	// ��Ϊhalconֻʶ��char�͵���Ҫ��cstringת��char
	//ReadImage(&ho_image, HTuple(CT2CA(str.GetBuffer())));
	ReadImage(&ho_image, szFileNameA);

	GetImageSize(ho_image, &hv_width, &hv_height);

	//SetPart(ho_WindleHandle, 0, 0, rtWindow.Height()-1, rtWindow.Width()-1);
	//HDevWindowStack::Push(hv_WindleHandle);

	SetPart(hv_WindleHandle, 0, 0, hv_height - 1, hv_width - 1);
	DispObj(ho_image, hv_WindleHandle);
}


void CMFCApplication6Dlg::OnBnClickedSmallK()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// Substract the small K

	//��ȡ��������������Ϊ����
	CString pers;
	Edit_K_pers.GetWindowText(pers);

	CString rows;
	Edit_K_rows.GetWindowText(rows);

	CString cols;
	Edit_K_cols.GetWindowText(cols);

	//����ת��
	k_rows = _wtoi(rows);
	k_cols = _wtoi(cols);
	k_pers = _wtoi(pers);

	bStartConfidence = 0; // �����ʼֵ
	bool b_StartConfidence;

	b_StartConfidence = GetLabelImageInfo(ho_image, k_pers, k_rows, k_cols, nChannel, bStartConfidence, hStartRow,
		hRowSpace,hStartCol,hColSpace,hCatSingleLabelImage);
	
	//��ȡ��Ϣ����ʾСKͼ
	HTuple hv_width2, hv_height2;
	GetImageSize(hCatSingleLabelImage, &hv_width2, &hv_height2);

	SetPart(hv_WindleHandle2, 0, 0, hv_height2 - 1, hv_width2 - 1);
	DispObj(hCatSingleLabelImage, hv_WindleHandle2);

	nChannel = 1;
	// ��ʾ��Ϣ
	int n_Channel = nChannel;
	// ��ת���ַ�������ǿ��ת��ΪLPCTSTR
	CString str;
	str.Format(_T("%d"), n_Channel);
	LPCTSTR pChannel = LPCTSTR(str);
	m_Label_5.SetWindowText(pChannel);

	if (b_StartConfidence){
		m_label_6.SetWindowText(_T("True"));
	}
	else
		m_label_6.SetWindowText(_T("False")); 
	
	CString str_row0;
	str_row0.Format(_T("%.4f"), hStartRow[0].D());
	LPCTSTR pStartRow = LPCTSTR(str_row0);
	m_label_7.SetWindowText(pStartRow);

	CString str_row;
	str_row.Format(_T("%.4f"), hRowSpace[0].D());
	LPCTSTR pRow = LPCTSTR(str_row);
	m_label_8.SetWindowText(pRow);

	CString str_col0;
	str_col0.Format(_T("%.4f"), hStartCol[0].D());
	LPCTSTR pStartCol = LPCTSTR(str_col0);
	m_label_9.SetWindowText(pStartCol);

	CString str_col;
	str_col.Format(_T("%.4f"), hColSpace.D());
	LPCTSTR pCol = LPCTSTR(str_col);
	m_label_10.SetWindowText(pCol);

}

bool CMFCApplication6Dlg::GetLabelImageInfo(const HObject hCatSearchImage,
	const int nLabelPeriod, const int nLabelRow, const int nLabelCol,
	int& nChannel,
	BOOL& bStartConfidence,
	HTuple& hStartRow, HTuple& hRowSpace,
	HTuple& hStartCol, HTuple& hColSpace,
	HObject& hCatSingleLabelImage){

	//��ʼ�������Ϣ
	hStartRow = 0;
	try{
		//�������
		// Local iconic variables
		HObject  ho_Image, ho_GrayImage, ho_Rectangle1;
		HObject  ho_ImageReduced, ho_ImagePart1, ho_Rectangle2, ho_ImageReduced1;
		HObject  ho_ImagePart2, ho_Rectangle3, ho_ImageReduced2;
		HObject  ho_ImagePart3, ho_ImageSub, ho_ImageSub_1, ho_ImageSub_2;
		HObject  ho_ImageResult, ho_ImageResult1, ho_GraySub, ho_ImageEmphasize;
		HObject  ho_ImageReduced3, ho_Rectangle4, ho_ImageReduced4;
		HObject  ho_ImagePart4, ho_Rectangle5, ho_ImageReduced5;
		HObject  ho_ImagePart5, ho_ImageSub2, ho_ImageSub2_1, ho_ImageSub2_2;
		HObject  ho_ImageResult_2, ho_ImageResult2, ho_GraySub2;
		HObject  ho_ImageEmphasize1, ho_Rectangle, ho_SmallKReduced;
		HObject  ho_SmallK;

		// Local control variables
		HTuple  hv_tuple_k_rows, hv_tuple_k_cols, hv_ImageFiles;
		HTuple  hv_IndexImage, hv_Width, hv_Height;
		HTuple  hv_WindowHandle, hv_t1, hv_Height_Rect, hv_Width2;
		HTuple  hv_Height2, hv_Width1, hv_Height1, hv_rectange_width;
		HTuple  hv_rect_col, hv_prev_width, hv_Width4, hv_Height4;
		HTuple  hv_HorProjection, hv_VertProjection, hv_Function;
		HTuple  hv_SmoothedFunction, hv_FirstDerivative, hv_ZeroCrossings;
		HTuple  hv_SecondDerivative, hv_Max, hv_Threshold, hv_Greatereq;
		HTuple  hv_left_part_value, hv_right_part_value, hv_move_dis;
		HTuple  hv_small_K_width, hv_middle_parts, hv_middle_Y_parts;
		HTuple  hv_points_loc, hv_Y_value, hv_Sorted, hv_sort_point_index;
		HTuple  hv_index_0, hv_good_index, hv_points_num, hv_search_num;
		HTuple  hv_good_label, hv_index, hv_good_index_sorted, hv_mean_width;
		HTuple  hv_Mean_Width, hv_leftest_pos, hv_rightest_pos;
		HTuple  hv_col0, hv_col1, hv_Valid_Width, hv_Width_Rect;
		HTuple  hv_Width3, hv_Height3, hv_HorProjection1, hv_VertProjection1;
		HTuple  hv_Function1, hv_SmoothedFunction1, hv_FirstDerivative1;
		HTuple  hv_ZeroCrossings1, hv_middle_parts1, hv_middle_Y_parts1;
		HTuple  hv_Y_value1, hv_Sorted1, hv_sort_point_index1, hv_good_index1;
		HTuple  hv_search_num1, hv_good_label1, hv_good_index1_sorted;
		HTuple  hv_mean_height, hv_Mean_Height, hv_gu_value, hv_row0;
		HTuple  hv_row1, hv_FirstDerivativeReplaced, hv_Greater0;
		HTuple  hv_Index0, hv_Index1, hv_t2, hv_WidthK, hv_HeightK;

		ConvertImageType(hCatSearchImage, &ho_Image, "uint2");

		GetImageSize(ho_image, &hv_Width, &hv_Height);

		Rgb1ToGray(ho_Image, &ho_GrayImage);

		// ����ֱ�ӳ���3��������

		k_rows = k_rows * 3;

		hv_Height_Rect = hv_Height / (8 * k_rows);

		if (HDevWindowStack::IsOpen())
			SetDraw(HDevWindowStack::GetActive(), "margin");
		//��ȡ��һ����
		GenRectangle2(&ho_Rectangle1, hv_Height / 2, hv_Width / 2, 0, hv_Width / 2, hv_Height_Rect);

		ReduceDomain(ho_GrayImage, ho_Rectangle1, &ho_ImageReduced);
		CropDomain(ho_ImageReduced, &ho_ImagePart1);
		GetImageSize(ho_ImagePart1, &hv_Width2, &hv_Height2);
		//��ȡ�ڶ�����
		GenRectangle2(&ho_Rectangle2, (hv_Height / 2) - (3 * hv_Height_Rect), hv_Width / 2, 0,
			hv_Width / 2, hv_Height_Rect);
		ReduceDomain(ho_GrayImage, ho_Rectangle2, &ho_ImageReduced1);
		CropDomain(ho_ImageReduced1, &ho_ImagePart2);
		ZoomImageSize(ho_ImagePart2, &ho_ImagePart2, hv_Width2, hv_Height2, "constant");

		//��ȡ��������Σ�����³����
		GenRectangle2(&ho_Rectangle3, (hv_Height / 2) + (3 * hv_Height_Rect), hv_Width / 2, 0,
			hv_Width / 2, hv_Height_Rect);
		ReduceDomain(ho_GrayImage, ho_Rectangle3, &ho_ImageReduced2);
		CropDomain(ho_ImageReduced2, &ho_ImagePart3);
		ZoomImageSize(ho_ImagePart3, &ho_ImagePart3, hv_Width2, hv_Height2, "constant");

		AbsDiffImage(ho_ImagePart1, ho_ImagePart2, &ho_ImageSub, 0.1);
		AbsDiffImage(ho_ImagePart2, ho_ImagePart3, &ho_ImageSub_1, .1);
		AbsDiffImage(ho_ImagePart1, ho_ImagePart3, &ho_ImageSub_2, .1);

		AddImage(ho_ImageSub, ho_ImageSub_1, &ho_ImageResult, 1, 0);
		AddImage(ho_ImageResult, ho_ImageSub_2, &ho_ImageResult1, 1, 0);

		GetImageSize(ho_ImageResult1, &hv_Width1, &hv_Height1);

		Rgb1ToGray(ho_ImageResult1, &ho_GraySub);
		//�Ȼ�ȡ���ROI
		//*********************************************************************************
		hv_rectange_width = 10;

		hv_rect_col = 0;
		//��¼����һ����λ��
		hv_prev_width = 0;

		if (HDevWindowStack::IsOpen())
			SetColor(HDevWindowStack::GetActive(), "yellow");

		//���þ��εĸ߶�ΪGraySub�ĸ߶�
		GetImageSize(ho_GraySub, &hv_Width4, &hv_Height4);

		Emphasize(ho_GraySub, &ho_ImageEmphasize, hv_Width4, hv_Height4, 1);

		//In the first one, calculate the grayhisto.
		GrayProjections(ho_ImageEmphasize, ho_ImageEmphasize, "simple", &hv_HorProjection,
			&hv_VertProjection);
		CreateFunct1dArray(hv_VertProjection, &hv_Function);
		SmoothFunct1dGauss(hv_Function, 2, &hv_SmoothedFunction);
		DerivateFunct1d(hv_SmoothedFunction, "first", &hv_FirstDerivative);
		ZeroCrossingsFunct1d(hv_FirstDerivative, &hv_ZeroCrossings);
		DerivateFunct1d(hv_SmoothedFunction, "second", &hv_SecondDerivative);
		TupleMax(hv_SmoothedFunction, &hv_Max);


		//������ֵΪ�߶ȵ�һ��
		hv_Threshold = hv_Max / 6;
		//�ȳ�ȥ�������˵�
		TupleGreaterEqualElem(hv_SmoothedFunction, hv_Threshold, &hv_Greatereq);
		//�ҵ����˵�
		TupleFindFirst(hv_Greatereq, 1, &hv_left_part_value);
		TupleFindLast(hv_Greatereq, 1, &hv_right_part_value);

		//��������ƫ��������ȥƫ����
		hv_move_dis = (hv_right_part_value - hv_left_part_value) / 50;

		hv_left_part_value = hv_left_part_value - hv_move_dis;
		hv_right_part_value += hv_move_dis;


		//ȷ�������ұ߽�֮�󣬸������ұ߽磬ȷ��СKͼ�Ĵ��¿��
		hv_small_K_width = ((hv_right_part_value - hv_left_part_value) - (k_cols * 50)) / k_cols;

		//�����ȥ����ʣ�µ�
		hv_middle_parts = HTuple();
		hv_middle_Y_parts = HTuple();

		//ȡ�м䲿�ֵļ�����Сֵ
		{
			HTuple end_val113 = (hv_ZeroCrossings.TupleLength()) - 1;
			HTuple step_val113 = 1;
			for (hv_points_loc = 0; hv_points_loc.Continue(end_val113, step_val113); hv_points_loc += step_val113)
			{
				if (0 != (HTuple(HTuple(hv_ZeroCrossings[hv_points_loc]) > hv_left_part_value).TupleAnd(HTuple(hv_ZeroCrossings[hv_points_loc]) < hv_right_part_value)))
				{
					//�����м䲿�ֵ��ֵ
					GetYValueFunct1d(hv_SmoothedFunction, HTuple(hv_ZeroCrossings[hv_points_loc]),
						"constant", &hv_Y_value);
					hv_middle_Y_parts = hv_middle_Y_parts.TupleConcat(hv_Y_value);
					hv_middle_parts = hv_middle_parts.TupleConcat(HTuple(hv_ZeroCrossings[hv_points_loc]));
				}
			}
		}

		TupleSort(hv_middle_Y_parts, &hv_Sorted);

		//��¼��ǰ�����λ������
		hv_sort_point_index = 0;
		//�ȼ�¼��һ�����Ժ�����Ƚ�
		TupleFindFirst(hv_middle_Y_parts, HTuple(hv_Sorted[0]), &hv_index_0);
		hv_good_index = HTuple(hv_middle_parts[hv_index_0]);

		//��¼����������ĸ���
		hv_points_num = 0;
		hv_search_num = 1;

		//����֮�����������ã�Ϊ�˼������߽磬5��6�߽�
		while (0 != (hv_points_num <= (k_cols + 1)))
		{
			TupleFindFirst(hv_middle_Y_parts, HTuple(hv_Sorted[hv_search_num]), &hv_sort_point_index);
			//���һ�����������е������߶������Զ
			hv_good_label = 1;
			{
				HTuple end_val139 = (hv_good_index.TupleLength()) - 1;
				HTuple step_val139 = 1;
				for (hv_index = 0; hv_index.Continue(end_val139, step_val139); hv_index += step_val139)
				{
					if (0 != (((HTuple(hv_middle_parts[hv_sort_point_index]) - HTuple(hv_good_index[hv_index])).TupleAbs()) < (hv_small_K_width - 100)))
					{
						hv_good_label = 0;
						break;
					}
				}
			}
			if (0 != (hv_good_label == 1))
			{
				hv_good_index = hv_good_index.TupleConcat(HTuple(hv_middle_parts[hv_sort_point_index]));
				hv_points_num += 1;
			}
			//Ϊ�˷�ֹ�Ҳ�������������������
			if (0 != (hv_search_num < ((hv_Sorted.TupleLength()) - 1)))
			{
				hv_search_num += 1;
			}
			else
			{
				break;
			}
		}

		//�������/�ұ߽�����
		TupleSort(hv_good_index, &hv_good_index_sorted);
		//�����ֵ

		if (0 != (k_cols >= 2))
		{
			hv_mean_width = HTuple();
			{
				HTuple end_val163 = (hv_good_index_sorted.TupleLength()) - 2;
				HTuple step_val163 = 1;
				for (hv_index = 0; hv_index.Continue(end_val163, step_val163); hv_index += step_val163)
				{
					hv_mean_width = hv_mean_width.TupleConcat(HTuple(hv_good_index_sorted[hv_index + 1]) - HTuple(hv_good_index_sorted[hv_index]));
				}
			}

			TupleMean(hv_mean_width, &hv_Mean_Width);

			hv_leftest_pos = HTuple(hv_good_index_sorted[1]) - hv_Mean_Width;
			hv_rightest_pos = HTuple(hv_good_index_sorted[(hv_good_index_sorted.TupleLength()) - 2]) + hv_Mean_Width;

			//�����滻���ұ߽�
			TupleReplace(hv_good_index_sorted, 0, hv_leftest_pos, &hv_good_index_sorted);
			TupleReplace(hv_good_index_sorted, (hv_good_index_sorted.TupleLength()) - 1,
				hv_rightest_pos, &hv_good_index_sorted);

			hv_col0 = ((const HTuple&)hv_good_index_sorted)[0];
			hv_col1 = ((const HTuple&)hv_good_index_sorted)[1];



			// ���¼���СKͼ��ֵ���
			if (0 != (k_cols > 2))
			{
				hv_mean_width = HTuple();
				{
					HTuple end_val303 = (hv_good_index_sorted.TupleLength()) - 2;
					HTuple step_val303 = 1;
					for (hv_index = 0; hv_index.Continue(end_val303, step_val303); hv_index += step_val303)
					{
						hv_mean_width = hv_mean_width.TupleConcat(HTuple(hv_good_index_sorted[hv_index + 1]) - HTuple(hv_good_index_sorted[hv_index]));
					}
				}
			}


			TupleMean(hv_mean_width, &hv_Mean_Width);

		}
		else
		{
			//����ǵ��� ��ֵ����
			hv_col0 = hv_left_part_value;
			hv_col1 = hv_right_part_value;

			hv_Mean_Width = hv_right_part_value - hv_left_part_value;

		}
		
		//��ʾ
		if (0 != ((hv_good_index_sorted.TupleLength()) > 2))
		{
			{
				HTuple end_val187 = (hv_good_index_sorted.TupleLength()) - 1;
				HTuple step_val187 = 0;
				for (hv_points_num = 0; hv_points_num.Continue(end_val187, step_val187); hv_points_num += step_val187)
				{
					DispLine(hv_WindowHandle, 0, HTuple(hv_good_index_sorted[hv_points_num]),
						hv_Height, HTuple(hv_good_index_sorted[hv_points_num]));
				}
			}
		}

		//******************************************************************************
		//******************************************************************************

		//ȷ�������õĿ��
		hv_Valid_Width = hv_right_part_value - hv_left_part_value;

		hv_Width_Rect = hv_left_part_value + (hv_Valid_Width / 2);

		//��ȡ��һ����
		GenRectangle2(&ho_Rectangle3, hv_Height / 2, hv_Width_Rect, 0, hv_Valid_Width / (k_cols * 6),
			hv_Height / 2);
		ReduceDomain(ho_GrayImage, ho_Rectangle3, &ho_ImageReduced3);
		CropDomain(ho_ImageReduced3, &ho_ImagePart3);
		GetImageSize(ho_ImagePart3, &hv_Width3, &hv_Height3);

		//��ȡ�ڶ�����
		GenRectangle2(&ho_Rectangle4, hv_Height / 2, (hv_Width_Rect - ((2 * hv_Valid_Width) / (k_cols * 6))) + 10,
			0, hv_Valid_Width / (k_cols * 5), hv_Height / 2);
		ReduceDomain(ho_GrayImage, ho_Rectangle4, &ho_ImageReduced4);
		CropDomain(ho_ImageReduced4, &ho_ImagePart4);
		ZoomImageSize(ho_ImagePart4, &ho_ImagePart4, hv_Width3, hv_Height3, "constant");

		//��ȡ��������
		GenRectangle2(&ho_Rectangle5, hv_Height / 2, (hv_Width_Rect + ((2 * hv_Valid_Width) / (k_cols * 6))) - 10,
			0, hv_Valid_Width / (k_cols * 5), hv_Height / 2);
		ReduceDomain(ho_GrayImage, ho_Rectangle5, &ho_ImageReduced5);
		CropDomain(ho_ImageReduced5, &ho_ImagePart5);
		ZoomImageSize(ho_ImagePart5, &ho_ImagePart5, hv_Width3, hv_Height3, "constant");

		AbsDiffImage(ho_ImagePart3, ho_ImagePart4, &ho_ImageSub2, 0.1);
		AbsDiffImage(ho_ImagePart5, ho_ImagePart4, &ho_ImageSub2_1, .1);
		AbsDiffImage(ho_ImagePart3, ho_ImagePart5, &ho_ImageSub2_2, .1);

		AddImage(ho_ImageSub2, ho_ImageSub2_1, &ho_ImageResult_2, 1, 0);
		AddImage(ho_ImageResult_2, ho_ImageSub2_2, &ho_ImageResult2, 1, 0);

		Rgb1ToGray(ho_ImageResult2, &ho_GraySub2);
		Emphasize(ho_GraySub2, &ho_ImageEmphasize1, hv_Width3, hv_Height3, 1);
		//�Ҷ�ͶӰ
		GrayProjections(ho_ImageEmphasize1, ho_ImageEmphasize1, "simple", &hv_HorProjection1,
			&hv_VertProjection1);
		CreateFunct1dArray(hv_HorProjection1, &hv_Function1);
		SmoothFunct1dGauss(hv_Function1, 2, &hv_SmoothedFunction1);
		DerivateFunct1d(hv_SmoothedFunction1, "first", &hv_FirstDerivative1);
		ZeroCrossingsFunct1d(hv_FirstDerivative1, &hv_ZeroCrossings1);


		//�����ȥ����ʣ�µ�
		hv_middle_parts1 = HTuple();
		hv_middle_Y_parts1 = HTuple();

		//ȡ�м䲿�ֵļ�����Сֵ
		{
			HTuple end_val248 = (hv_ZeroCrossings1.TupleLength()) - 1;
			HTuple step_val248 = 1;
			for (hv_points_loc = 0; hv_points_loc.Continue(end_val248, step_val248); hv_points_loc += step_val248)
			{
				//�����м䲿�ֵ��ֵ
				if (0 != (HTuple(hv_ZeroCrossings1[hv_points_loc]) > 5))
				{
					GetYValueFunct1d(hv_SmoothedFunction1, HTuple(hv_ZeroCrossings1[hv_points_loc]),
						"constant", &hv_Y_value1);
					hv_middle_Y_parts1 = hv_middle_Y_parts1.TupleConcat(hv_Y_value1);
					hv_middle_parts1 = hv_middle_parts1.TupleConcat(HTuple(hv_ZeroCrossings1[hv_points_loc]));
				}
			}
		}

		TupleSort(hv_middle_Y_parts1, &hv_Sorted1);

		//��¼����������ĸ���
		hv_points_num = 0;
		//��¼��ǰ�����λ������
		hv_sort_point_index1 = 0;
		//�ȼ�¼��һ�����Ժ�����Ƚ�
		TupleFindFirst(hv_middle_Y_parts1, HTuple(hv_Sorted1[0]), &hv_index_0);
		hv_good_index1 = HTuple(hv_middle_parts1[hv_index_0]);

		hv_search_num1 = 1;

		//��ʱ����Ҫ��ȥ2����ʱ����Ҫ��ȥ1

		while (0 != (hv_points_num < (k_rows - 2)))
		{
			TupleFindFirst(hv_middle_Y_parts1, HTuple(hv_Sorted1[hv_search_num1]), &hv_sort_point_index1);
			//���һ�����������е������߶������Զ
			hv_good_label1 = 1;
			{
				HTuple end_val275 = (hv_good_index1.TupleLength()) - 1;
				HTuple step_val275 = 1;
				for (hv_index = 0; hv_index.Continue(end_val275, step_val275); hv_index += step_val275)
				{
					if (0 != (((HTuple(hv_middle_parts1[hv_sort_point_index1]) - HTuple(hv_good_index1[hv_index])).TupleAbs()) < 100))
					{
						hv_good_label1 = 0;
						break;
					}
				}
			}

			if (0 != (hv_good_label1 == 1))
			{
				hv_good_index1 = hv_good_index1.TupleConcat(HTuple(hv_middle_parts1[hv_sort_point_index1]));
				//disp_line (WindowHandle, middle_parts1[sort_point_index1], 0, middle_parts1[sort_point_index1], Width)
				hv_points_num += 1;
			}
			//Ϊ�˷�ֹ�Ҳ�������������������
			if (0 != (hv_search_num1 < ((hv_Sorted1.TupleLength()) - 1)))
			{
				hv_search_num1 += 1;
			}
			else
			{
				break;
			}

		}

		//������ϡ��±߽�����
		TupleSort(hv_good_index1, &hv_good_index1_sorted);
		//�����ֵ

		if (0 != (k_rows > 2))
		{
			hv_mean_height = HTuple();
			{
				HTuple end_val302 = (hv_good_index1_sorted.TupleLength()) - 2;
				HTuple step_val302 = 1;
				for (hv_index = 0; hv_index.Continue(end_val302, step_val302); hv_index += step_val302)
				{
					hv_mean_height = hv_mean_height.TupleConcat(HTuple(hv_good_index1_sorted[hv_index + 1]) - HTuple(hv_good_index1_sorted[hv_index]));
				}
			}

			TupleMean(hv_mean_height, &hv_Mean_Height);

			//�ж������ֵ���ֵ���̫��
			hv_gu_value = hv_Height / k_rows;
			if (0 != (((hv_Mean_Height - hv_gu_value) / hv_gu_value) > 0.3))
			{
				//˵�������������
				//�ټ�һ��
				while (0 != (hv_search_num1 < ((hv_Sorted1.TupleLength()) - 1)))
				{
					TupleFindFirst(hv_middle_Y_parts1, HTuple(hv_Sorted1[hv_search_num1]),
						&hv_sort_point_index1);
					hv_good_label1 = 1;
					{
						HTuple end_val316 = (hv_good_index1.TupleLength()) - 1;
						HTuple step_val316 = 1;
						for (hv_index = 0; hv_index.Continue(end_val316, step_val316); hv_index += step_val316)
						{
							if (0 != (((HTuple(hv_middle_parts1[hv_sort_point_index1]) - HTuple(hv_good_index1[hv_index])).TupleAbs()) < 100))
							{
								hv_good_label1 = 0;
								break;
							}
						}
					}
					if (0 != (hv_good_label1 == 1))
					{
						hv_good_index1 = hv_good_index1.TupleConcat(HTuple(hv_middle_parts1[hv_sort_point_index1]));
						break;
					}
					hv_search_num1 += 1;
				}
			}
			//��ʹ���������ȷ�������п��ܹ��ƴ�
			TupleSort(hv_good_index1, &hv_good_index1_sorted);
			// ���¼���СKͼ��ֵ�߶�
			if (0 != (k_rows > 2))
			{
				hv_mean_height = HTuple();
				{
					HTuple end_val302 = (hv_good_index1_sorted.TupleLength()) - 2;
					HTuple step_val302 = 1;
					for (hv_index = 0; hv_index.Continue(end_val302, step_val302); hv_index += step_val302)
					{
						hv_mean_height = hv_mean_height.TupleConcat(HTuple(hv_good_index1_sorted[hv_index + 1]) - HTuple(hv_good_index1_sorted[hv_index]));
					}
				}

				TupleMean(hv_mean_height, &hv_Mean_Height);

				hv_row0 = hv_good_index1_sorted[0];
				hv_row1 = hv_good_index1_sorted[1];
			}
			else
			{
				//����ǵ��� ��ֵ����
				//�ҵ�һ�׵�����Ϊ0���׵㣬��һ�׵���Ϊ0��ĩ��
				TupleReplace(hv_FirstDerivative1, HTuple::TupleGenSequence(0, 5, 1), 0, &hv_FirstDerivativeReplaced);
				TupleGreaterElem(hv_FirstDerivativeReplaced, 0.05, &hv_Greater0);
				TupleFindFirst(hv_Greater0, 1, &hv_Index0);
				hv_row0 = hv_Index0;

				TupleFindLast(hv_Greater0, 1, &hv_Index1);

				hv_Mean_Height = (hv_Index1 - hv_Index0)/3;

				hv_row1 = hv_Index1;
			}
		}
		//��ʾ
	{
		HTuple end_val352 = (hv_good_index1.TupleLength()) - 1;
		HTuple step_val352 = 0;
		for (hv_points_num = 0; hv_points_num.Continue(end_val352, step_val352); hv_points_num += step_val352)
		{
			if (0 != ((hv_good_index1.TupleLength()) != 1))
			{
				DispLine(hv_WindowHandle, HTuple(hv_good_index1_sorted[hv_points_num]), 0,
					HTuple(hv_good_index1_sorted[hv_points_num]), hv_width);
			}
		}
	}
	
	hStartRow = hv_good_index1_sorted[0];
	hRowSpace = hv_Mean_Height;

	hStartCol = hv_good_index_sorted[0];
	hColSpace = hv_Mean_Width;



	//��ʾ����ʱ��
	//CountSeconds(&hv_t2);
	//WriteString(hv_WindowHandle, ("Time is: " + ((hv_t2 - hv_t1) * 1000)) + " ms ");

	//��ʾСKͼ

	GenRectangle1(&ho_Rectangle, hv_row0, hv_col0, hv_row1, hv_col1);
	ReduceDomain(ho_Image, ho_Rectangle, &ho_SmallKReduced);
	CropDomain(ho_SmallKReduced, &hCatSingleLabelImage);

	return true;
	
	}

	catch (HException& exception)
	{
		fprintf(stderr, "  Error #%u in %s: %s\n", exception.ErrorCode(),
			(const char *)exception.ProcName(),
			(const char *)exception.ErrorMessage());
		return false;
	}

}

