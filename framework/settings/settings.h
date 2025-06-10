#include "imgui.h"

#include <D3DX11tex.h>
#pragma comment(lib, "D3DX11.lib")

class c_settings
{
public:
        c_settings();
        bool load(const std::string& path);
        void apply_style(ImGuiStyle& style) const;

        struct
        {
                ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;

		std::string name = "S\nY\nN\nT\nH\nE\nT\nI\nC";

                ImVec2 window_size = ImVec2(720, 540);
                ImVec2 padding = ImVec2(8, 8);
                ImVec2 item_spacing = ImVec2(6, 6);

                float scrollbar_size = 18.f;
                float border_size = 0.f;

                float general_rounding = 16.f;
                float rounding = 12.f;

		bool slider_hovered = false;
                ImGuiID slider_id = 0;
        } c_window;

        struct
        {
                ImVec2 size = ImVec2(100, 32);
                float rounding = 6.f;
                float border = 1.f;
        } c_button;

	struct
	{
                ImVec2 child_window_padding = ImVec2(8, 8);
                ImVec2 child_item_spacing = ImVec2(8, 8);

                float rounding = 10.f;

	} c_child;

	struct
	{
                float rounding = 6.f;

	} c_element;

	struct
	{
                float size = 12.f;
                float rounding = 8.f;
                ImVec2 padding = ImVec2(6, 6);
                ImVec2 picker_size = ImVec2(140, 90);
                ImVec2 bar_size = ImVec2(picker_size.x, 6);
	} c_picker;

	struct
	{
		ID3D11ShaderResourceView* bg = nullptr;
		ID3D11ShaderResourceView* logo = nullptr;

	} c_texture;

	struct
	{
		ImFont* icon[7];
		ImFont* inter_medium[2];
		ImFont* name;

	} c_font;

};

inline c_settings* set = new c_settings();

class c_colors
{
public:

	struct
	{
		ImVec4 col_bg_alpha_0 = ImColor(125, 125, 125, 255);
		ImVec4 col_bg_alpha_1 = ImColor(185, 185, 185, 255);

                ImVec4 accent_clr = ImColor(255, 85, 160, 255);

		ImVec4 black_clr = ImColor(0, 0, 0, 255);
		ImVec4 white_clr = ImColor(255, 255, 255, 255);

	} c_other_clr;

	struct
	{
                ImVec4 general_layout = ImColor(30, 30, 38, 180);
                ImVec4 general_stroke = ImColor(70, 40, 90, 255);

                ImVec4 layout = ImColor(24, 22, 32, 255);
                ImVec4 stroke = ImColor(60, 40, 80, 255);

	} c_window;

	struct
	{
                ImVec4 layout = ImColor(30, 24, 40, 255);
                ImVec4 stroke = ImColor(70, 50, 90, 255);

	} c_child;

        struct
        {
                ImVec4 dropdown_selection_layout = ImColor(50, 40, 65, 255);
                ImVec4 popup_icon = ImColor(70, 60, 90, 255);

                ImVec4 checkbox_active = ImColor(70, 40, 90, 255);
                ImVec4 separator = ImColor(60, 40, 80, 255);

                ImVec4 layout = ImColor(34, 24, 46, 255);
                ImVec4 circle = ImColor(70, 50, 90, 255);

        } c_element;

        struct
        {
                ImVec4 background = ImColor(34, 24, 46, 255);
                ImVec4 hover = ImColor(70, 40, 90, 255);
                ImVec4 active = ImColor(90, 60, 120, 255);
                ImVec4 border = ImColor(60, 40, 80, 255);
        } c_button;

	struct
	{
                ImVec4 text_active = ImColor(255, 255, 255, 255);
                ImVec4 text_hov = ImColor(180, 180, 200, 255);
                ImVec4 text = ImColor(120, 120, 140, 255);

	} c_text;

	struct
	{
                ImVec4 background = ImColor(24, 20, 30);
                ImVec4 stroke = ImColor(70, 40, 90);
	} c_lua;

};

inline c_colors* clr = new c_colors();

