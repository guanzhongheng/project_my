#pragma once

#include <moore/node/node.hpp>

#include <boost/thread.hpp>

#include <set>

#include <QtGui>
#include <QtWidgets>

namespace moore_qt
{
class wallet;
class eventloop_processor : public QObject
{
public:
	bool event (QEvent *) override;
};
class eventloop_event : public QEvent
{
public:
	eventloop_event (std::function<void()> const &);
	std::function<void()> action;
};
class settings
{
public:
	settings (moore_qt::wallet &);
	void refresh_representative ();
	void activate ();
	void update_locked (bool, bool);
	QWidget * window;
	QVBoxLayout * layout;
	QLineEdit * password;
	QPushButton * lock_toggle;
	QFrame * sep1;
	QLineEdit * new_password;
	QLineEdit * retype_password;
	QPushButton * change;
	QFrame * sep2;
	QLabel * representative;
	QLabel * current_representative;
	QLineEdit * new_representative;
	QPushButton * change_rep;
	QPushButton * back;
	moore_qt::wallet & wallet;
};
class advanced_actions
{
public:
	advanced_actions (moore_qt::wallet &);
	QWidget * window;
	QVBoxLayout * layout;
	QPushButton * show_ledger;
	QPushButton * show_peers;
	QPushButton * language_change;
	QPushButton * bootstrap;
	QPushButton * wallet_refresh;
	QPushButton * create_block;
	QPushButton * enter_block;
	QPushButton * block_viewer;
	QPushButton * account_viewer;
	QWidget * scale_window;
	QHBoxLayout * scale_layout;
	QLabel * scale_label;
	QButtonGroup * ratio_group;
	QRadioButton * mrai;
	QRadioButton * krai;
	QRadioButton * rai;
	QPushButton * back;

	QWidget * ledger_window;
	QVBoxLayout * ledger_layout;
	QStandardItemModel * ledger_model;
	QTableView * ledger_view;
	QPushButton * ledger_refresh;
	QPushButton * ledger_back;

	QWidget * peers_window;
	QVBoxLayout * peers_layout;
	QStandardItemModel * peers_model;
	QTableView * peers_view;
	QLabel * bootstrap_label;
	QLineEdit * bootstrap_line;
	QPushButton * peers_bootstrap;
	QPushButton * peers_refresh;
	QPushButton * peers_back;

	moore_qt::wallet & wallet;

private:
	void refresh_ledger ();
	void refresh_peers ();
};
class block_entry
{
public:
	block_entry (moore_qt::wallet &);
	QWidget * window;
	QVBoxLayout * layout;
	QPlainTextEdit * block;
	QLabel * status;
	QPushButton * process;
	QPushButton * back;
	moore_qt::wallet & wallet;
};
class block_creation
{
public:
	block_creation (moore_qt::wallet &);
	void deactivate_all ();
	void activate_send ();
	void activate_receive ();
	void activate_change ();
	void activate_open ();
	void create_send ();
	void create_receive ();
	void create_change ();
	void create_open ();
	QWidget * window;
	QVBoxLayout * layout;
	QButtonGroup * group;
	QHBoxLayout * button_layout;
	QRadioButton * send;
	QRadioButton * receive;
	QRadioButton * change;
	QRadioButton * open;
	QLabel * account_label;
	QLineEdit * account;
	QLabel * source_label;
	QLineEdit * source;
	QLabel * amount_label;
	QLineEdit * amount;
	QLabel * destination_label;
	QLineEdit * destination;
	QLabel * representative_label;
	QLineEdit * representative;
	QPlainTextEdit * block;
	QLabel * status;
	QPushButton * create;
	QPushButton * back;
	moore_qt::wallet & wallet;
};
class self_pane
{
public:
	self_pane (moore_qt::wallet &, rai::account const &);
	void refresh_balance ();
	QWidget * window;
	QVBoxLayout * layout;
	QHBoxLayout * self_layout;
	QWidget * self_window;
	QLabel * your_account_label;
	QLabel * version;
	QWidget * account_window;
	QHBoxLayout * account_layout;
	QLineEdit * account_text;
	QPushButton * copy_button;
	QWidget * balance_window;
	QHBoxLayout * balance_layout;
	QLabel * balance_label;
	moore_qt::wallet & wallet;
};
class accounts
{
public:
	accounts (moore_qt::wallet &);
	void refresh ();
	void refresh_wallet_balance ();
	QLabel * wallet_balance_label;
	QWidget * window;
	QVBoxLayout * layout;
	QStandardItemModel * model;
	QTableView * view;
	QPushButton * use_account;
	QPushButton * create_account;
	QPushButton * import_wallet;
	QPushButton * backup_seed;
	QFrame * separator;
	QLineEdit * account_key_line;
	QPushButton * account_key_button;
	QPushButton * back;
	moore_qt::wallet & wallet;
};
class import
{
public:
	import (moore_qt::wallet &);
	QWidget * window;
	QVBoxLayout * layout;
	QLabel * seed_label;
	QLineEdit * seed;
	QLabel * clear_label;
	QLineEdit * clear_line;
	QPushButton * import_seed;
	QFrame * separator;
	QLabel * filename_label;
	QLineEdit * filename;
	QLabel * password_label;
	QLineEdit * password;
	QPushButton * perform;
	QPushButton * back;
	moore_qt::wallet & wallet;
};
class history
{
public:
	history (rai::ledger &, rai::account const &, moore_qt::wallet &);
	void refresh ();
	QWidget * window;
	QVBoxLayout * layout;
	QStandardItemModel * model;
	QTableView * view;
	QWidget * tx_window;
	QHBoxLayout * tx_layout;
	QLabel * tx_label;
	QSpinBox * tx_count;
	rai::ledger & ledger;
	rai::account const & account;
	moore_qt::wallet & wallet;
};
class block_viewer
{
public:
	block_viewer (moore_qt::wallet &);
	void rebroadcast_action (rai::uint256_union const &);
	QWidget * window;
	QVBoxLayout * layout;
	QLabel * hash_label;
	QLineEdit * hash;
	QLabel * block_label;
	QPlainTextEdit * block;
	QLabel * successor_label;
	QLineEdit * successor;
	QPushButton * retrieve;
	QPushButton * rebroadcast;
	QPushButton * back;
	moore_qt::wallet & wallet;
};
class account_viewer
{
public:
	account_viewer (moore_qt::wallet &);
	QWidget * window;
	QVBoxLayout * layout;
	QLabel * account_label;
	QLineEdit * account_line;
	QPushButton * refresh;
	QWidget * balance_window;
	QHBoxLayout * balance_layout;
	QLabel * balance_label;
	moore_qt::history history;
	QPushButton * back;
	rai::account account;
	moore_qt::wallet & wallet;
};
enum class status_types
{
	not_a_status,
	disconnected,
	working,
	locked,
	vulnerable,
	active,
	synchronizing,
	nominal
};
class status
{
public:
	status (moore_qt::wallet &);
	void erase (moore_qt::status_types);
	void insert (moore_qt::status_types);
	void set_text ();
	std::string text ();
	std::string color ();
	std::set<moore_qt::status_types> active;
	moore_qt::wallet & wallet;
};
class wallet : public std::enable_shared_from_this<moore_qt::wallet>
{
public:
    wallet (QApplication &, moore_qt::eventloop_processor &, rai::node &, std::shared_ptr<rai::wallet>, rai::account &, std::string &);
	void start ();
	void refresh ();
	void update_connected ();
	void empty_password ();
	void change_rendering_ratio (rai::uint128_t const &);
	std::string format_balance (rai::uint128_t const &) const;
	rai::uint128_t rendering_ratio;
	rai::node & node;
	std::shared_ptr<rai::wallet> wallet_m;
	rai::account & account;
    std::string & language;
	moore_qt::eventloop_processor & processor;
	moore_qt::history history;
	moore_qt::accounts accounts;
	moore_qt::self_pane self;
	moore_qt::settings settings;
	moore_qt::advanced_actions advanced;
	moore_qt::block_creation block_creation;
	moore_qt::block_entry block_entry;
	moore_qt::block_viewer block_viewer;
	moore_qt::account_viewer account_viewer;
	moore_qt::import import;

	QApplication & application;
	QLabel * status;
	QStackedWidget * main_stack;

	QWidget * client_window;
	QVBoxLayout * client_layout;

	QWidget * entry_window;
	QVBoxLayout * entry_window_layout;
	QFrame * separator;
	QLabel * account_history_label;
	QPushButton * send_blocks;
	QPushButton * settings_button;
	QPushButton * accounts_button;
	QPushButton * show_advanced;

	QWidget * send_blocks_window;
	QVBoxLayout * send_blocks_layout;
	QLabel * send_account_label;
	QLineEdit * send_account;
	QLabel * send_count_label;
	QLineEdit * send_count;
	QPushButton * send_blocks_send;
	QPushButton * send_blocks_back;

	moore_qt::status active_status;
	void pop_main_stack ();
	void push_main_stack (QWidget *);
	void change_language();
};
}
