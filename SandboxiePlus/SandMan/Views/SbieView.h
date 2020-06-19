
#include "../../MiscHelpers/Common/PanelView.h"
#include "../../MiscHelpers/Common/TreeviewEx.h"
#include "../Models/SbieModel.h"

class CSbieView : public CPanelView
{
	Q_OBJECT
public:
	CSbieView(QWidget* parent = 0);
	virtual ~CSbieView();

	virtual QTreeViewEx*		GetTree() { return m_pSbieTree; }

	virtual QList<CSandBoxPtr>	GetSelectedBoxes();
	virtual QList<CBoxedProcessPtr>	GetSelectedProcesses();

public slots:
	void						Refresh();

private slots:
	void						ProcessSelection(const QItemSelection& selected, const QItemSelection& deselected);

	void						OnSandBoxAction();
	void						OnProcessAction();

	void						OnBoxCleaned();

protected:
	virtual void				OnMenu(const QPoint& Point);
	virtual QTreeView*			GetView() { return m_pSbieTree; }
	virtual QAbstractItemModel* GetModel() { return m_pSortProxy; }

private:

	QVBoxLayout*			m_pMainLayout;

	QTreeViewEx*			m_pSbieTree;
	CSbieModel*				m_pSbieModel;
	QSortFilterProxyModel*	m_pSortProxy;


	QMenu*					m_pMenuRun;
	QAction*				m_pMenuRunAny;
	QAction*				m_pMenuRunBrowser;
	QAction*				m_pMenuRunExplorer;
	QAction*				m_pMenuRunCmd;
	QAction*				m_pMenuEmptyBox;
	QAction*				m_pMenuCleanUp;
	QAction*				m_pMenuRemove;
	QAction*				m_pMenuRename;
	int						m_iMenuBox;
	QAction*				m_pMenuTerminate;
	QAction*				m_pMenuSuspend;
	QAction*				m_pMenuResume;
	int						m_iMenuProc;

	int						m_BoxesToClean;
};