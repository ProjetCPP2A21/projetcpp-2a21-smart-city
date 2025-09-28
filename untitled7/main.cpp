#include <QApplication>
#include <QWidget>
#include <QListWidget>
#include <QTreeWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSplitter>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QTableWidget>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPixmap>
#include <QIcon>

class InventoryUI : public QWidget {
public:
    InventoryUI(QWidget* parent = nullptr) : QWidget(parent) {
        // Left side navigation panel
        QTreeWidget* navigation = new QTreeWidget();
        navigation->setHeaderHidden(true);

        QTreeWidgetItem* dashboardItem = new QTreeWidgetItem(QStringList() << "Dashboard");
        QTreeWidgetItem* contactsItem = new QTreeWidgetItem(QStringList() << "Contacts");
        QTreeWidgetItem* itemsItem = new QTreeWidgetItem(QStringList() << "Items");
        itemsItem->addChild(new QTreeWidgetItem(QStringList() << "Item Groups"));
        itemsItem->addChild(new QTreeWidgetItem(QStringList() << "Item Adjustments"));
        itemsItem->addChild(new QTreeWidgetItem(QStringList() << "Transfer Orders"));

        QTreeWidgetItem* salesOrdersItem = new QTreeWidgetItem(QStringList() << "Sales Orders");
        QTreeWidgetItem* packagesItem = new QTreeWidgetItem(QStringList() << "Packages");
        QTreeWidgetItem* invoicesItem = new QTreeWidgetItem(QStringList() << "Invoices");
        QTreeWidgetItem* purchaseOrdersItem = new QTreeWidgetItem(QStringList() << "Purchase Orders");
        QTreeWidgetItem* integrationsItem = new QTreeWidgetItem(QStringList() << "Integrations");
        QTreeWidgetItem* reportsItem = new QTreeWidgetItem(QStringList() << "Reports");

        navigation->addTopLevelItem(dashboardItem);
        navigation->addTopLevelItem(contactsItem);
        navigation->addTopLevelItem(itemsItem);
        navigation->addTopLevelItem(salesOrdersItem);
        navigation->addTopLevelItem(packagesItem);
        navigation->addTopLevelItem(invoicesItem);
        navigation->addTopLevelItem(purchaseOrdersItem);
        navigation->addTopLevelItem(integrationsItem);
        navigation->addTopLevelItem(reportsItem);

        navigation->expandAll();

        // Middle panel: List of active items
        QWidget* middlePanel = new QWidget();
        QVBoxLayout* middleLayout = new QVBoxLayout(middlePanel);

        QLabel* activeItemsLabel = new QLabel("<b>Active Items</b>");
        QPushButton* addButton = new QPushButton("+ New");

        QHBoxLayout* topMiddleLayout = new QHBoxLayout();
        topMiddleLayout->addWidget(activeItemsLabel);
        topMiddleLayout->addStretch();
        topMiddleLayout->addWidget(addButton);

        QListWidget* activeItemsList = new QListWidget();
        activeItemsList->addItems({"Sample1 / green", "Sample1 / red", "Sample1 / pink", "Sample1 / green (2)", "SO", "SO check prod", "Sony Xperia 22", "Test from 4Back", "TestProductType1", "TestProductType2", "Men's Birthday Gift", "Tea Tray"});

        middleLayout->addLayout(topMiddleLayout);
        middleLayout->addWidget(activeItemsList);

        // Right panel: Details of selected item
        QWidget* rightPanel = new QWidget();
        QVBoxLayout* rightLayout = new QVBoxLayout(rightPanel);

        // Header with title and buttons
        QHBoxLayout* headerLayout = new QHBoxLayout();
        QLabel* titleLabel = new QLabel("<b>Hanswooly Cotton casual shirt-M/slim fit</b>");
        headerLayout->addWidget(titleLabel);
        headerLayout->addStretch();

        QPushButton* adjustStockBtn = new QPushButton("Adjust Stock");
        QPushButton* moreBtn = new QPushButton("More");
        headerLayout->addWidget(adjustStockBtn);
        headerLayout->addWidget(moreBtn);

        // Tabs for Overview, Transactions, Adjustments, History
        QTabWidget* tabWidget = new QTabWidget();

        // Overview Tab
        QWidget* overviewTab = new QWidget();
        QVBoxLayout* overviewLayout = new QVBoxLayout(overviewTab);

        // Sales Information
        QGroupBox* salesInfoGroup = new QGroupBox("Sales Information");
        QFormLayout* salesFormLayout = new QFormLayout(salesInfoGroup);

        salesFormLayout->addRow("Selling Price:", new QLabel("$50.00"));
        salesFormLayout->addRow("Sales Account:", new QLabel("Sales"));

        // Stock Locations Table
        QTableWidget* stockTable = new QTableWidget(3, 5);
        QStringList headers = {"Warehouse Name", "Stock On Hand", "Accounting Stock", "Committed Stock", "Available for Sale"};
        stockTable->setHorizontalHeaderLabels(headers);
        stockTable->setItem(0, 0, new QTableWidgetItem("Zyler W1"));
        stockTable->setItem(0, 1, new QTableWidgetItem("12.00"));
        stockTable->setItem(0, 2, new QTableWidgetItem("5.00"));
        stockTable->setItem(0, 3, new QTableWidgetItem("0.00"));
        stockTable->setItem(0, 4, new QTableWidgetItem("100"));

        stockTable->setItem(1, 0, new QTableWidgetItem("Zyler W2"));
        stockTable->setItem(1, 1, new QTableWidgetItem("0.00"));
        stockTable->setItem(1, 2, new QTableWidgetItem("0.00"));
        stockTable->setItem(1, 3, new QTableWidgetItem("0.00"));
        stockTable->setItem(1, 4, new QTableWidgetItem("0.00"));

        stockTable->setItem(2, 0, new QTableWidgetItem("Zyler W3"));
        stockTable->setItem(2, 1, new QTableWidgetItem("0.00"));
        stockTable->setItem(2, 2, new QTableWidgetItem("0.00"));
        stockTable->setItem(2, 3, new QTableWidgetItem("0.00"));
        stockTable->setItem(2, 4, new QTableWidgetItem("0.00"));

        stockTable->setEditTriggers(QAbstractItemView::NoEditTriggers); // read-only

        // Sales Cost Section
        QFormLayout* costLayout = new QFormLayout();
        costLayout->addRow("Purchase Cost:", new QLabel("$22.00"));
        costLayout->addRow("Purchase Account:", new QLabel("Cost of Goods Sold"));
        costLayout->addRow("Preferred Vendor:", new QLabel("Adam John"));

        overviewLayout->addWidget(salesInfoGroup);
        overviewLayout->addWidget(stockTable);
        overviewLayout->addLayout(costLayout);

        tabWidget->addTab(overviewTab, "Overview");

        // Transactions Tab placeholder
        QWidget* transactionsTab = new QWidget();
        tabWidget->addTab(transactionsTab, "Transactions");

        // Adjustments Tab placeholder
        QWidget* adjustmentsTab = new QWidget();
        tabWidget->addTab(adjustmentsTab, "Adjustments");

        // History Tab placeholder
        QWidget* historyTab = new QWidget();
        tabWidget->addTab(historyTab, "History");

        // Image and stock block summary on the bottom right
        QHBoxLayout* bottomRightLayout = new QHBoxLayout();

        QLabel* itemImage = new QLabel();
        QPixmap pixmap(100, 100);
        pixmap.fill(Qt::orange); // Placeholder color
        itemImage->setPixmap(pixmap);
        itemImage->setFixedSize(100, 100);

        QVBoxLayout* stockSummaryLayout = new QVBoxLayout();

        QLabel* openingStockLabel = new QLabel("<b>Opening Stock: 0.00</b>");
        QLabel* accountingStockLabel = new QLabel("Accounting Stock:");
        QLabel* blockOnHandLabel = new QLabel("Block on Hand: 10.00");
        QLabel* committedStockLabel = new QLabel("Committed Stock: 0.00");
        QLabel* availableForSaleLabel = new QLabel("Available for Sale: 10.00");
        QLabel* physicalStockLabel = new QLabel("Physical Stock: 0.00");

        stockSummaryLayout->addWidget(openingStockLabel);
        stockSummaryLayout->addWidget(accountingStockLabel);
        stockSummaryLayout->addWidget(blockOnHandLabel);
        stockSummaryLayout->addWidget(committedStockLabel);
        stockSummaryLayout->addWidget(availableForSaleLabel);
        stockSummaryLayout->addWidget(physicalStockLabel);

        bottomRightLayout->addWidget(itemImage);
        bottomRightLayout->addLayout(stockSummaryLayout);

        rightLayout->addLayout(headerLayout);
        rightLayout->addWidget(tabWidget);
        rightLayout->addLayout(bottomRightLayout);

        // Main splitter for left, middle, and right panels
        QSplitter* mainSplitter = new QSplitter();
        mainSplitter->addWidget(navigation);
        mainSplitter->addWidget(middlePanel);
        mainSplitter->addWidget(rightPanel);

        // Set resize behavior
        mainSplitter->setStretchFactor(0, 1);
        mainSplitter->setStretchFactor(1, 2);
        mainSplitter->setStretchFactor(2, 3);

        QHBoxLayout* mainLayout = new QHBoxLayout(this);
        mainLayout->addWidget(mainSplitter);

        setLayout(mainLayout);
        setWindowTitle("Inventory Management UI");
        resize(1200, 700);
    }
};

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    InventoryUI window;
    window.show();

    return app.exec();
}
